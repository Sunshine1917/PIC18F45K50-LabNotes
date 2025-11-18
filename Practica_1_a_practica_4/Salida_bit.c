/*
 * File:   main.c
 * Author: Alejandro Juarez Rojas
 *
 * Created on November 17, 2025, 12:23 PM
 * 
 * Description: Programa simple para demostrar la salida en bit
 */


#include <xc.h>
#include <pic18f45k50.h>

#pragma config CONFIG1L = 0x00
#pragma config CONFIG1H = 0x28 // FOSC=INTIO (1000), PCLKEN= 1 (Reloj Siempre encendido)
#pragma config CONFIG2L = 0x44 // PWRTEN=ON, BOREN=ON(no-sleep), BORV=2.85V
#pragma config CONFIG2H = 0x00 // WatchDog desabilitado 
#pragma config CONFIG4L = 0x81 // // CONFIG4L: Debugger OFF, LVP (Bajo Voltaje) OFF 

void setUp(void){
    // Port D configuration (digital outputs)
    TRISD = 0x00;   // All outputs
    ANSELD = 0x00;  // All digital
    LATD = 0x00;    // Initialize to 0
}


void main(void) {
    
    setUp();
    
    while (1) {
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD3 = 1;
        LATDbits.LATD4 = 1;
        LATDbits.LATD5 = 1;
        LATDbits.LATD6 = 1;
        LATDbits.LATD7 = 1;
    }
}

