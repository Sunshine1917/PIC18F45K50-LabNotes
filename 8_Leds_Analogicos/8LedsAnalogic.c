/*
 * File:   main.c
 * Author: alejandrojuarezrojas
 *
 * Created on September 12, 2025, 7:57 AM
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

void setupAnalogic(void){
    ANSELD = 0XFF; // 0 = digital || 1 = analógico
    TRISD = 0X00; // 0= Salida || 1 = entrada
    LATD = 0x00; 
}

int main(void) {
    config16MHz();
    setupAnalogic();
    
    while(1){
        LATD = 0X01;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x02;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x04;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x08;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x10;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x20;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x40;
        __delay_ms(1000);
        LATD = 0X00;
        LATD = 0x80;
        __delay_ms(1000);
        LATD = 0X00;
    }
    
    return 0;
}
