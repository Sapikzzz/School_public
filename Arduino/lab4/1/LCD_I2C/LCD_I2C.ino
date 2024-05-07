#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#include "LCDI2C.h"

#ifndef _BV
#define _BV(bit)        (1<<(bit))
#endif
#ifndef sbi
#define sbi(reg,bit)    reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)    reg &= ~(_BV(bit))
#endif

#ifndef tbi
#define tbi(reg,bit)    reg ^= (_BV(bit))
#endif
//
//
//void timerInit() {
//  //Wybranie trybu pracy CTC z TOP OCR1A
//  sbi(TCCR1B, WGM12);
//  cbi(TCCR1B, WGM13);
//  cbi(TCCR1A, WGM11);
//  cbi(TCCR1A, WGM10);
// 
//  //Wybranie dzielnika czestotliwosci - częstotliwość Atmega328: 16 MHz
//  sbi(TCCR1B, CS12);
//  cbi(TCCR1B, CS11);
//  cbi(TCCR1B, CS10);
// 
//  //Zapisanie do OCR1A wartosci odpowiadajacej 0,5s
//  OCR1A = 62500;
// 
//  //Uruchomienie przerwania OCIE1A
//  sbi(TIMSK1, OCIE1A);
//}

int8_t liczba = 100;
int8_t godzina = 0;

int main() {
  //timerInit();
  sbi(EICRA, ISC01);
  cbi(EICRA, ISC00);
  sbi(EIMSK, INT0);
  //0x27 - adres urzadzenia na I2C
  LCD_I2C Lcd = LCD_I2C(0x27);
  _delay_ms(100);
  Lcd.backLightOn();
  //sei();


  uint8_t i = 0;
  char text[20];
  char text2[20];

  DDRB = 0x00;
  PORTB = 0x0F;
  
  DDRD = 0xFF;
  while (1) {

    
     if(bit_is_clear(PINB, 1)){
    _delay_ms(20);
        if(bit_is_clear(PINB, 1)){
          if(liczba < 100){
           liczba++;
          }
        }
        while (bit_is_clear(PINB, 1));
      }


     if(bit_is_clear(PINB, 0)){
        _delay_ms(20);
        if(bit_is_clear(PINB, 0)){
          if(liczba > -100){
           liczba--;
          }
        }
        while (bit_is_clear(PINB, 0));
      }
    
    //i = (i + 1) % 60;
    Lcd.clear();
    sprintf(text, "%d", liczba);
    Lcd.writeText(text);
    Lcd.goTo(0, 1);
    //sprintf(text2, "17:52:%d", liczba);
    Lcd.writeText(text2);

    if(godzina == liczba){
      sbi(PORTD, 0);
    }
    
    _delay_ms(150);
  }
}


//ISR(TIMER1_COMPA_vect) {
//  godzina=(godzina+1) % 60;
//}
