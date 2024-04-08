#include <iostream>
#include <string>
#include "priority_queue.h"
#include <vector>
#include <utility>
#include <random>
#include <algorithm>
#include <chrono>

std::vector<std::pair<std::string, int>> shuffleVector(const std::vector<std::pair<std::string, int>>& input) {
    std::vector<std::pair<std::string, int>> shuffled = input;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int main() {
    PriorityQueue<std::string> packets;
    PriorityQueue<std::string> packetsShuffled;
    std::string message, packet, receivedMessage;
    int packetLength, priority = 1;
    bool ifPacket = false;
    std::vector<std::pair<std::string, int>> packetPair;

    while(1){
        std::cout << "1. Wprowadz wiadomosc" << std::endl;
        std::cout << "2. Wprowadz dlugosc pakietu" << std::endl;
        std::cout << "3. Podziel wiadomosc" << std::endl;
        std::cout << "4. Wyswietl pakiety" << std::endl;
        std::cout << "5. Symulacja odebrania pakietow w losowej kolejnosci" << std::endl;
        std::cout << "6. Wyswietl pakiety w losowej kolejnosci" << std::endl;
        std::cout << "7. Wyswietl odebrana wiadomosc" << std::endl;
        std::cout << "8. Zakoncz" << std::endl;
        char option;
        std::cin >> option;

        switch(option){
            case '1':
                std::cout << "Wprowadz wyslana wiadomosc: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, message);
                break;
            case '2':
                if(message.empty()){
                    std::cout << "Najpierw wprowadz wiadomosc" << std::endl;
                    break;
                }
                std::cout << "Wprowadz dlugosc pakietu: " << std::endl;
                std::cin >> packetLength;
                break;
            case '3':
                if(message.empty()){
                    std::cout << "Najpierw wprowadz wiadomosc" << std::endl;
                    break;
                }
                std::cout << "Wiadomosc zostala podzielona " << std::endl;
                for (int i = 0; i < message.length(); i += packetLength) {
                    packet = message.substr(i, packetLength);
                    packets.push(packet, priority);
                    packetPair.push_back(std::make_pair(packet, priority));
                    priority++;
                }
                ifPacket = true;
                break;
            case '4':
                if(message.empty()){
                    std::cout << "Najpierw wprowadz wiadomosc" << std::endl;
                    break;
                } else if(!ifPacket){
                    std::cout << "Najpierw podziel wiadomosc" << std::endl;
                    break;
                }
                std::cout << "Wiadomosc w pakietach: " << std::endl;
                packets.printAll();
                break;
            case '5':
                if(message.empty()){
                    std::cout << "Najpierw wprowadz wiadomosc" << std::endl;
                    break;
                }
                std::cout << "Symulacja odebrania pakietow w losowej kolejnosci" << std::endl;
                packetPair = shuffleVector(packetPair);
                for (int i = 0; i < packetPair.size(); i++) {
                    packetsShuffled.push(packetPair[i].first, packetPair[i].second);
                }
                break;
            case '6':
                if(message.empty()){
                    std::cout << "Najpierw wprowadz wiadomosc" << std::endl;
                    break;
                } else if(!ifPacket){
                    std::cout << "Najpierw podziel wiadomosc" << std::endl;
                    break;
                }
                std::cout << "Wiadomosc w pakietach: " << std::endl;
                packetsShuffled.printAll();
                break;
            case '7':
                if(message.empty()){
                    std::cout << "Najpierw wprowadz wiadomosc" << std::endl;
                    break;
                }
                std::cout << "Odebrana wiadomosc: " << std::endl;
                while (!packetsShuffled.empty()) {
                    receivedMessage += packetsShuffled.removeMin();
                }
                std::cout << receivedMessage << std::endl;
                ifPacket = false;
                break;
            case '8':
                return 0;
                break;
            default:
                std::cout << "Nie ma takiej opcji" << std::endl;
                break;
        }
    }
//    for(int i = 40000; i > 0; i--){
//        packets.push("Wiadomosc " + std::to_string(i), i);
//    }
//    std::cout << "Packets created" << std::endl;
//    //packets.printAll();
//    auto start = std::chrono::high_resolution_clock::now();
//    while (!packets.empty()) {
//        receivedMessage += packets.removeMin();
//                }
//
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed = end - start;
//    std::cout << "Removing all packets took: " << elapsed.count() << "s" << std::endl;


    return 0;
}
