/*
 * File:   main.c
 * Author: alejandrojuarezrojas
 *
 * Created on November 17, 2025, 2:22 PM
 * 
 * Description: Programa simple para demostrar la salida en byte 
 */


#include <xc.h>
#include <pic18f45k50.h>

#define _XTAL_FREQ 16000000  // 16 MHz (oscilador interno)

#pragma config CONFIG1L = 0x00
#pragma config CONFIG1H = 0x28 // FOSC=INTIO (1000), PCLKEN= 1 (Reloj Siempre encendido)
#pragma config CONFIG2L = 0x44 // PWRTEN=ON, BOREN=ON(no-sleep), BORV=2.85V
#pragma config CONFIG2H = 0x00 // WatchDog desabilitado 
#pragma config CONFIG4L = 0x81 // // CONFIG4L: Debugger OFF, LVP (Bajo Voltaje) OFF 

void setUp(void){
    
    OSCCON = 0x70;  // Pone el Oscilador Interno a 16 MHz
    
    // Port D configuration (digital outputs)
    TRISD = 0x00;   // All outputs
    ANSELD = 0x00;  // All digital
    LATD = 0x00;    // Initialize to 0
}


void main(void) {
    
    setUp();
    
    while (1) {
        LATD = 0xFF;
        __delay_ms(1000);
        LATD = 0x00;
        __delay_ms(1000);
    }
}


