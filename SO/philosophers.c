#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/time.h>
#include <stdbool.h>

typedef enum { THINKING, HUNGRY, EATING } State;

struct timeval start_time;
struct timeval *philosopher_state_start_time;
struct timeval *last_eaten_time;

pthread_mutex_t mutex;
pthread_mutex_t output_mutex;
State *state;
sem_t *both_forks_available;
bool *forks_in_use;
int num_philosophers;
int program_running = 1;

int left(int i) { 
    return (i - 1 + num_philosophers) % num_philosophers; 
}

int right(int i) { 
    return (i + 1) % num_philosophers; 
}

int my_rand(unsigned int min, unsigned int max) {
    return min + rand() % (max - min + 1);
}

void update_status(int i) {
    struct timeval now, elapsed;
    gettimeofday(&now, NULL);
    timersub(&now, &philosopher_state_start_time[i], &elapsed);
    
    char* state_str;      
    char forks_str[20] = "";
    
    if (state[i] == THINKING) {
    	state_str = "THINKING";
    	}
    else if (state[i] == HUNGRY) {
    	state_str = "HUNGRY";
    	}
    else {
    	state_str = "EATING";
    	sprintf(forks_str, "Forks %d and %d", left(i) + 1, i + 1);
    	}
    
    pthread_mutex_lock(&output_mutex);
    if (state[i] == HUNGRY){
    	attron(COLOR_PAIR(1));
    	}
    else if (state[i] == EATING){
    	attron(COLOR_PAIR(2));
    	}
    else if (state[i] == THINKING){
    	attron(COLOR_PAIR(3));
    	}
    mvprintw(i + 1, 0, "%-100s", "");   
    mvprintw(i + 1, 0, "Philosopher %d", i + 1);
    mvprintw(i + 1, 15, "| %s", state_str);
    if (state[i] == HUNGRY){
    	attroff(COLOR_PAIR(1));
    	}
    else if (state[i] == EATING){
    	attroff(COLOR_PAIR(2));
    	}
    else if (state[i] == THINKING){
    	attroff(COLOR_PAIR(3));
    	}
    mvprintw(i + 1, 30, "| %s", forks_str);
    mvprintw(i + 1, 50, "| %ld.%lds", elapsed.tv_sec, elapsed.tv_usec / 100000);
    refresh();
    pthread_mutex_unlock(&output_mutex);
}

void set_state(int i, State new_state) {
    state[i] = new_state;
    gettimeofday(&philosopher_state_start_time[i], NULL);
    update_status(i);
}

void test(int i) {
    struct timeval now;
    gettimeofday(&now, NULL);
    
    int waited_time_i = now.tv_sec - last_eaten_time[i].tv_sec;
    int waited_time_left = now.tv_sec - last_eaten_time[left(i)].tv_sec;
    int waited_time_right = now.tv_sec - last_eaten_time[right(i)].tv_sec;
    if (state[i] == HUNGRY && state[left(i)] != EATING && state[right(i)] != EATING && waited_time_i >= waited_time_left && waited_time_i >= waited_time_right) {
        set_state(i, EATING);
        sem_post(&both_forks_available[i]);
    }
}

void think(int i) {
    set_state(i, THINKING);
    usleep(my_rand(4000, 13000) * 1000);
}

void take_forks(int i) {
    pthread_mutex_lock(&mutex);
    set_state(i, HUNGRY);
    test(i);
    pthread_mutex_unlock(&mutex);
    sem_wait(&both_forks_available[i]);
    pthread_mutex_lock(&mutex);
    forks_in_use[i] = true;
    forks_in_use[left(i)] = true;
    pthread_mutex_unlock(&mutex);
}

void eat(int i) {
    set_state(i, EATING);
    usleep(my_rand(4000, 13000) * 1000);
    gettimeofday(&last_eaten_time[i], NULL);
}

void put_forks(int i) {     
    pthread_mutex_lock(&mutex);
    forks_in_use[i] = false;
    forks_in_use[left(i)] = false;
    set_state(i, THINKING);
    test(left(i));
    test(right(i));
    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;
    while (program_running) {
        think(i);
        take_forks(i);
        eat(i);
        put_forks(i);
    }
    return NULL;
}

void display_forks() {
    pthread_mutex_lock(&output_mutex);
    mvprintw(num_philosophers + 2, 0, "Forks:  ");
    for (int i = 0; i < num_philosophers; i++) {
        if (forks_in_use[i] == true) {
        	attron(COLOR_PAIR(1));
        	}
        else {
        	attron(COLOR_PAIR(2));
        	}
        printw("  %d  ", i + 1);
                if (forks_in_use[i] == true) {
        	attroff(COLOR_PAIR(1));
        	}
        else {
        	attroff(COLOR_PAIR(2));
        	}
    }
    refresh();
    pthread_mutex_unlock(&output_mutex);
}

void* status_updater() {
    while (program_running) {
        for (int i = 0; i < num_philosophers; i++) {
            update_status(i);
        }
        display_forks();
        usleep(100000);
    }
    return NULL;
}

void* keyboard_listener() {
    keypad(stdscr, TRUE); 

    while (1) {
        int ch = getch();
        if (ch != ERR) {
            program_running = 0;
            break;
        }
        usleep(100000);
    }
    return NULL;
}

int main(int argc, char *argv[]) {   \
    num_philosophers = atoi(argv[1]);
    gettimeofday(&start_time, NULL);
    
    char start_str[100];
    time_t start_sec = start_time.tv_sec;
    struct tm *tm_start = localtime(&start_sec);

    
    if (argc != 2) {
   	fprintf(stderr, "Enter number of philosophers\n");
	return 1;
    }

    if (num_philosophers <= 0) {
        fprintf(stderr, "Number of philosophers must be a positive integer\n");
        return 1;
    }

    srand(time(NULL));
    pthread_t threads[num_philosophers], input_thread, status_thread;
    state = malloc(num_philosophers * sizeof(State));
    philosopher_state_start_time = malloc(num_philosophers * sizeof(struct timeval));
    both_forks_available = malloc(num_philosophers * sizeof(sem_t));
    forks_in_use = malloc(num_philosophers * sizeof(bool));
    last_eaten_time = malloc(num_philosophers * sizeof(struct timeval));
    int philosophers[num_philosophers];

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&output_mutex, NULL);
    
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    
    
    mvprintw(0, 0, "Philosopher");
    mvprintw(0, 15, "| State");
    mvprintw(0, 30, "| Forks");
    mvprintw(0, 50, "| Duration");
    strftime(start_str, sizeof(start_str), "Time of start:	%H:%M:%S", tm_start);
    mvprintw(num_philosophers + 4, 0, "%s", start_str);
    refresh();

    for (int i = 0; i < num_philosophers; i++) {
    	gettimeofday(&last_eaten_time[i], NULL);
    }

    for (int i = 0; i < num_philosophers; i++) {
        sem_init(&both_forks_available[i], 0, 0);
        forks_in_use[i] = false;
        state[i] = THINKING;
        gettimeofday(&philosopher_state_start_time[i], NULL);
        philosophers[i] = i;
    }

    pthread_create(&input_thread, NULL, keyboard_listener, NULL);
    pthread_create(&status_thread, NULL, status_updater, NULL);

    for (int i = 0; i < num_philosophers; i++) {
        pthread_create(&threads[i], NULL, philosopher, &philosophers[i]);
    }

    pthread_join(input_thread, NULL);
    
    pthread_cancel(status_thread);
    for (int i = 0; i < num_philosophers; i++) {
        pthread_cancel(threads[i]);
    }

    pthread_join(status_thread, NULL);
    for (int i = 0; i < num_philosophers; i++) {
        pthread_join(threads[i], NULL);
    }

    endwin();

    for (int i = 0; i < num_philosophers; i++) {
        sem_destroy(&both_forks_available[i]);
    }
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&output_mutex);

    free(state);
    free(philosopher_state_start_time);
    free(both_forks_available);
    free(forks_in_use);

    return 0;
}