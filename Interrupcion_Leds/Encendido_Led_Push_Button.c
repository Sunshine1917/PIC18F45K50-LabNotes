/*
 * File:   main.c
 * Author: alejandrojuarezrojas
 *
 * Created on September 12, 2025, 10:53 PM
 */


#include <xc.h>
#define _XTAL_FREQ 16000000
#pragma config CONFIG1H = 0x28

// Global variables
unsigned char programa_actual = 0;
unsigned char cambio_programa = 0;

void config16MHz(void);
void configInterrupciones(void);
void setUpSistemaDigital(void);
void setUpSistemaAnalogico(void);
void programaUno(void);
void programaDos(void);
void programaTres(void);
void programaCuatro(void);

void __interrupt() isr(void){
    // ¿Fue INT0 la que interrumpió?
    if(INTCON & 0x02){  // Máscara: 0000 0010 - revisar INT0IF (bit 1)
        
        // Anti-rebote simple
        __delay_ms(50);
        
        // ¿Sigue presionado el botón? (RB0 en bajo por pull-up)
        if(!(PORTB & 0x01)){  // Máscara: 0000 0001 - revisar RB0
            programa_actual++;
            if(programa_actual > 3) programa_actual = 0;
            cambio_programa = 1;
        }
        
        // Limpiar bandera de INT0
        INTCON &= ~0x02;  // Máscara: 1111 1101 - limpiar INT0IF
    }
}

void config16MHz(void){
    // Configurar oscilador interno a 16MHz
    OSCCON |= 0x72;  // Máscara: 0111 0010 - 16MHz internal oscillator
    while(!OSCCONbits.HFIOFS);  // Esperar estabilización
}

void configInterrupciones(void){
    // Configurar INT0 para flanco de bajada (botón presionado)
    INTCON2 &= ~0x40; // Máscara: 1011 1111 - INTEDG0 = 0 (flanco de bajada)
    
    // Limpiar bandera de INT0
    INTCON &= ~0x02;  // Máscara: 1111 1101 - limpiar INT0IF (bit 1)
    
    // Habilitar INT0
    INTCON |= 0x10;   // Máscara: 0001 0000 - habilitar INT0IE (bit 4)
    
    // Habilitar interrupciones globales
    INTCON |= 0x80;   // Máscara: 1000 0000 - habilitar GIE (bit 7)
}

void setUpSistemaDigital(void){
    // Configuración puerto D (salidas digitales)
    TRISD = 0x00;     // Todo como salida
    ANSELD = 0x00;    // Todo digital
    LATD = 0x00;      // Inicializar en 0
    
    // Configuración puerto B (RB0 como entrada)
    TRISB |= 0x01;    // Máscara: 0000 0001 - RB0 como entrada
    ANSELB = 0x00;    // Todo digital
    WPUB |= 0x01;     // Máscara: 0000 0001 - pull-up en RB0
    INTCON2 &= ~0x80; // Máscara: 0111 1111 - habilitar pull-ups globales
}

void setUpSistemaAnalogico(void){
    // Configuración puerto D (salidas analógicas)
    TRISD = 0x00;     // Todo como salida
    ANSELD = 0xFF;    // Todo analógico
    LATD = 0x00;      // Inicializar en 0
    
    // Configuración puerto B (RB0 como entrada digital para botón)
    TRISB |= 0x01;    // Máscara: 0000 0001 - RB0 como entrada
    ANSELB = 0x00;    // RB0 sigue siendo digital para el botón
    WPUB |= 0x01;     // Máscara: 0000 0001 - pull-up en RB0
    INTCON2 &= ~0x80; // Máscara: 0111 1111 - habilitar pull-ups globales
}

void programaUno(void){
    // Parpadeo simple en RD0
    LATD |= 0x01;     // Máscara: 0000 0001 - encender RD0
    __delay_ms(1000); 
    LATD = 0x00;      // Apagar todo el puerto
    __delay_ms(1000); 
}

void programaDos(void){
    // Parpadeo en RD3
    LATD |= 0x04;     // Máscara: 0000 1000 - encender RD3
    __delay_ms(1000); 
    LATD = 0x00;      // Apagar todo el puerto
    __delay_ms(1000); 
}

void programaTres(void){
    // Secuencia de LEDs (RD0 -> RD7)
    LATD = 0x01;      // RD0
    __delay_ms(1000);
    LATD = 0x02;      // RD1
    __delay_ms(1000);
    LATD = 0x40;      // RD2
    __delay_ms(1000);
    LATD = 0x80;      // RD3
    __delay_ms(1000);
    LATD = 0x20;      // RD4
    __delay_ms(1000);
    LATD = 0x10;      // RD5
    __delay_ms(1000);
    LATD = 0x08;      // RD6
    __delay_ms(1000);
    LATD = 0x04;      // RD7
    __delay_ms(1000);
    LATD = 0x00;      // Apagar todo
}

void programaCuatro(void){
    // Secuencia inversa (RD7 -> RD0)
    LATD = 0x04;      // RD7
    __delay_ms(1000);
    LATD = 0x08;      // RD6
    __delay_ms(1000);
    LATD = 0x10;      // RD5
    __delay_ms(1000);
    LATD = 0x20;      // RD4
    __delay_ms(1000);
    LATD = 0x80;      // RD3
    __delay_ms(1000);
    LATD = 0x40;      // RD2
    __delay_ms(1000);
    LATD = 0x02;      // RD1
    __delay_ms(1000);
    LATD = 0x01;      // RD0
    __delay_ms(1000);
    LATD = 0x00;      // Apagar todo
}

int main(void) {
    config16MHz();
    setUpSistemaDigital();  // Configurar hardware inicial
    configInterrupciones(); // Configurar interrupciones
    
    while(1){
        // Si hubo cambio de programa, limpiar estado
        if(cambio_programa){
            cambio_programa = 0;
            LATD = 0x00;  // Limpiar puerto D
            
            // Reconfigurar sistema si es necesario
            if(programa_actual == 1){  // Programa 2 necesita analógico
                setUpSistemaAnalogico();
            } else {
                setUpSistemaDigital();
            }
        }
        
        switch(programa_actual){
            case 0:
                programaUno();
                break;
            case 1:
                programaDos();
                break;
            case 2:
                programaTres();
                break;
            case 3:
                programaCuatro();
                break;
            default:
                programa_actual = 0;  // Por seguridad
                break;
        }
    }
    return 0;
}
