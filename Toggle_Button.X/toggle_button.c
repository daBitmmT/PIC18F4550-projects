/*
 * File:   main.c
 * Author: david
 *
 * Created on 20 de diciembre de 2023, 01:38 PM
 */

#include "config.h"
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000UL

void main(void) {
    ADCON1bits.PCFG = 0x0F;
    
    TRISDbits.RD0 = 1;
    TRISDbits.RD3 = 1;
    
    TRISBbits.RB0 = 0;
    LATBbits.LB0 = 0;
    
    int state = 0;
    
        while(1){
            if(PORTDbits.RD0 == 1){
                state = ~state;
                __delay_ms(200);
            }
            if(PORTDbits.RD3 == 1){
                state = ~state;
                __delay_ms(200);
            }
            LATBbits.LB0 = state;
        }
    return;
}
