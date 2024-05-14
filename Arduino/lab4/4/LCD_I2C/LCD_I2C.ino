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


void ADCinit(){
  // Ustawienie napięcia AVCC
  sbi(ADMUX, REFS0);
  cbi(ADMUX, REFS1);
  

  //Ustawienie podzielnika częstotliwosci na 128; 16 MHz/128 = 125000 Hz
  sbi(ADCSRA, ADPS0);
  sbi(ADCSRA, ADPS1);
  sbi(ADCSRA, ADPS2);

  //Uruchomienie ukladu przetwornika
  sbi(ADCSRA, ADEN);

  //Ustawienie kanalu ADC0
  cbi(ADMUX, MUX0);
  cbi(ADMUX, MUX1);
  cbi(ADMUX, MUX2);
  cbi(ADMUX, MUX3);
}

uint16_t ADC_10bit(){
  sbi(ADCSRA, ADSC);
  loop_until_bit_is_clear(ADCSRA, ADSC);
  return ADC;
}


int main() {
  //0x27 - adres urzadzenia na I2C
  LCD_I2C Lcd = LCD_I2C(0x27);
  _delay_ms(100);
  Lcd.backLightOn();
  ADCinit();
  
  uint8_t i = 0;
  char text[20];
  char text2[20];

  DDRB = 0x00;
  PORTB = 0x0F;
  DDRD = 0xFF;
  while (1) {
    float pomiar = ADC_10bit();
    uint16_t pomiar_wartosc = ADC_10bit();
    Lcd.clear();
    sprintf(text, "%d", pomiar_wartosc);
    Lcd.writeText(text);
    
    float pomiar_v = pomiar*5/1024;
    char volt[10];
    dtostrf(pomiar_v, 5, 2, volt); 
    Lcd.goTo(0,1);
    sprintf(text2, "Napiecie:%s", volt);
    Lcd.writeText(text2);
    _delay_ms(150);
  }
}
