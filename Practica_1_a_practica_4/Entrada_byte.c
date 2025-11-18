
/*
 * File:   main.c
 * Author: alejandrojuarezrojas
 * 
 * ENTRADA BYTE
 *
 * Created on November 17, 2025, 8:03 PM
 */


#include <xc.h>
#include <pic18f45k50.h>

#define _XTAL_FREQ 16000000  // 16 MHz (oscilador interno)

#pragma config CONFIG1L = 0x00
#pragma config CONFIG1H = 0x28 // FOSC=INTIO (1000), PCLKEN= 1 (Reloj Siempre encendido)
#pragma config CONFIG2L = 0x44 // PWRTEN=ON, BOREN=ON(no-sleep), BORV=2.85V
#pragma config CONFIG2H = 0x00 // WatchDog desabilitado 
#pragma config CONFIG4L = 0x81 // Debugger OFF, LVP (Bajo Voltaje) OFF

void setUp(void) {

    OSCCON = 0x70; // PONE EL OSCILADOR INTERNO A 16 MHz

    // CONFIGURACIÓN DEL PUERTO D (SALIDAS DIGITALES)
    TRISD = 0x00; // All outputs
    ANSELD = 0x00; // All digital
    LATD = 0x00; // Initialize to 0

    // CONFIGURACIÓN DEL PUERTO B 
    TRISB = 0xFF; // PIN RB1 CONFIGURADO COMO ENTRADA
    ANSELB = 0x00; // PONEMOS EL PIN RB1 EN MODO digital
    WPUB = 0xFF;
    INTCON2bits.RBPU = 0;
}

void main(void) {
    
    setUp();
    while(1){
        if(PORTB == 0x00){
        LATD = 0xFF;
    } else {
        LATD = 0x00;
    }
    }
}
