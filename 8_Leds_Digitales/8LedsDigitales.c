/*
 * =============================================================================
 * Proyecto: Control de 8 LEDs con PIC - salida digital 
 * =============================================================================
 * File:   main.c
 * Author: alejandrojuarezrojas
 *
 * Created on September 11, 2025, 10:53 PM
 */


#include <xc.h>

#define _XTAL_FREQ 16000000

#pragma config CONFIG1H = 0x28

void config16MHz(void);

void config16MHz(void){
    OSCCON = 0x00; //Limpia todo el registro
    
    // Configurar oscilador interno a 16MHz
    // Bit 7-4: IRCF<3:0> = 0111 (16MHz)
    // Bit 1: OSTS = 1 (Oscilador estable)
    // Bit 0: HFIOFS = se establece automáticamente cuando está listo
    OSCCON = OSCCON | 0x72; // Configura los bits en 01110010
    
    while(!OSCCONbits.HFIOFS);// Espera a que se estabilice HFINTOSC
}

int main(void) {
    config16MHz();
    
    ANSELD = ANSELD & 0X00;
    
    TRISD = TRISD & 0X00;
    while(1){
        LATD = LATD | 0X01;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x02;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x04;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x08;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x10;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x20;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x40;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        LATD = LATD | 0x80;
        __delay_ms(1000);
        LATD = LATD & 0X00;
        
    }
    return 0;
}
