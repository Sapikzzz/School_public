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
}

uint16_t ADC_channel1(){
  // Ustawienie kanalu ADC0
  cbi(ADMUX, MUX0);
  cbi(ADMUX, MUX1);
  cbi(ADMUX, MUX2);
  cbi(ADMUX, MUX3);
  
  sbi(ADCSRA, ADSC);
  loop_until_bit_is_clear(ADCSRA, ADSC);
  return ADC;
}

uint16_t ADC_channel2(){
  // Ustawienie kanalu ADC1
  sbi(ADMUX, MUX0);
  cbi(ADMUX, MUX1);
  cbi(ADMUX, MUX2);
  cbi(ADMUX, MUX3);
  
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
  DDRD = 0xFF;
  
  uint8_t i = 0;
  char text[20];
  char text2[20];

  bool LED_status = 0;
  uint8_t histereza = 40;
  DDRD = 0xFF;
  while (1) {
    uint16_t pomiar_adc1= ADC_channel1();
    uint16_t pomiar_adc2 = ADC_channel2();
    Lcd.clear();
    sprintf(text, "%d Foto: %d", pomiar_adc1, pomiar_adc2);
    Lcd.writeText(text);
    
//    Lcd.goTo(0,1);
//    sprintf(text2, "%d", pomiar_adc2);
//    Lcd.writeText(text2);

    if(pomiar_adc2 > (pomiar_adc1 + histereza)){
      sbi(PORTD, 0);
      LED_status = 1;
    }
    if(pomiar_adc2 < (pomiar_adc1 - histereza)){
      cbi(PORTD, 0); 
      LED_status = 0;
    }

    if(LED_status == 1){
      Lcd.goTo(0,1);
      sprintf(text2, "Light: ON");
      Lcd.writeText(text2);
    }
    else{
      Lcd.goTo(0,1);
      sprintf(text2, "Light: OFF");
      Lcd.writeText(text2);
  }
    _delay_ms(150);
  }
}
