/*
 * File:   main.c
 * Author: david
 *
 * Created on 20 de diciembre de 2023, 01:38 PM
 */

#include "config.h"
#include <pic18f4550.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000UL

int display[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int8_t i = 0;
int papu = 0;
int papunt = 0; 

void main(void) {
    TRISB = 0;
    LATB = 0;
    TRISDbits.RD0 = 1;
    TRISDbits.RD3 = 1; 
    
    while (1){
      if(PORTDbits.RD3 == 1){
          while(PORTDbits.RD3 == 1);
          __delay_ms(20);
          i++;
      }
        if( i > 9){
        i = 0;
        }
      
      if(PORTDbits.RD1 == 1){
          while(PORTDbits.RD1 == 1);
          __delay_ms(20);
          i--;
      }
        if( i < 0){
        i = 9;
        }
      
      LATB = display[i];
    __delay_ms(100);
    }
    return;
}
