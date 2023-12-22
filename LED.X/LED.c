/*
 * File:   LED.c
 * Author: david
 *
 * Created on 19 de diciembre de 2023, 10:55 PM
 */

#include <pic18f4550.h>
#include "config.h"
#define _XTAL_FREQ 8000000UL 

void main(void) {
        ADCON1bits.PCFG = 0x0F;      //   Pines digitales 
        TRISDbits.RD0 = 0x00;        //   Pin D0 como salida
        LATDbits.LD0 = 0;            //   Limpia el pin D0     
        TRISCbits.RC0 = 1;
        
        while(1){
            if(PORTCbits.RC0 == 1){
                LATDbits.LD0 = 1;
            }
            else{
                LATDbits.LD0 = 0;
            }
        }
//       while(1){
//          LATDbits.LD0 = 1;
//         __delay_ms(1000);
//          LATDbits.LD0 = 0;
//          __delay_ms(1000);
//       }
   return;
}