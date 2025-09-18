/*
 * =============================================================================
 * Proyecto: Control de LED con PIC - Ejemplo básico de parpadeo
 * =============================================================================
 * 
 * File:        main.c
 * Author:      Alejandro Juárez Rojas
 * Created:     September 11, 2025, 12:55 PM
 * 
 * Descripción:
 *   Programa básico que hace parpadear un LED conectado al pin RA4 de un 
 *   microcontrolador PIC. El LED se enciende y apaga cada segundo usando
 *   el oscilador interno configurado a 16MHz.
 * 
 * Hardware requerido:
 *   - Microcontrolador PIC18f45K50
 *   - LED conectado a RA4 con resistencia de 220 ohms
 *   - Fuente de alimentación 3.3V o 5V
 * 
 * Configuración de pines:
 *   - RA4: Salida digital para control de LED
 * 
 * Frecuencia del sistema: 16MHz (oscilador interno)
 * 
 * Versión: 1.0
 * Última modificación: September 11, 2025
 * 
 * =============================================================================
 */


#include <xc.h>

// =============================================================================
// DEFINICIONES Y CONFIGURACIONES
// =============================================================================

/**
 * @brief Frecuencia del cristal/oscilador para cálculos de delay
 * @note Esta definición es utilizada por las funciones __delay_ms() y __delay_us()
 */
#define _XTAL_FREQ 16000000

/**
 * @brief Configuración de bits de configuración del microcontrolador
 * @details CONFIG1H = 0x28 establece la configuración básica del PIC
 */
#pragma config CONFIG1H = 0x28

// =============================================================================
// PROTOTIPOS DE FUNCIONES
// =============================================================================
void config16MHz(void);

// =============================================================================
// IMPLEMENTACIÓN DE FUNCIONES
// =============================================================================

/**
 * @brief Configura el oscilador interno del PIC a 16MHz
 * @details Esta función configura el registro OSCCON para usar el oscilador
 *          interno de alta frecuencia (HFINTOSC) a 16MHz y espera a que se
 *          estabilice antes de continuar.
 * @param None
 * @return None
 * 
 * @note La función bloquea la ejecución hasta que el oscilador esté estable
 */
void config16MHz(void){
    OSCCON = 0x00; //Limpia todo el registro
    
    // Configurar oscilador interno a 16MHz
    // Bit 7-4: IRCF<3:0> = 0111 (16MHz)
    // Bit 1: OSTS = 1 (Oscilador estable)
    // Bit 0: HFIOFS = se establece automáticamente cuando está listo
    OSCCON = OSCCON | 0x72; // Configura los bits en 01110010
    
    while(!OSCCONbits.HFIOFS);// Espera a que se estabilice HFINTOSC
}

/**
 * @brief Función principal del programa
 * @details Inicializa el sistema y ejecuta un bucle infinito que hace
 *          parpadear un LED conectado al pin RA4 cada segundo.
 * @return int Estado de salida (nunca se alcanza en este programa)
 */
int main(void) {
    
    config16MHz(); // Configurar el oscilador del sistema a 16MHz
    
    // ==========================================================================
    // CONFIGURACIÓN DE PUERTOS
    // ==========================================================================
    
    // 1. Configurar RA4 como pin digital
    // NOTA: En algunos PICs, RA4 puede ser analógico por defecto
    // Descomentar la siguiente línea si es necesario:
    // ANSELA = ANSELA & 0xEF;  // Bit 4 = 0 (0xEF = 111011110)
    
    // 2. Configurar RA4 como salida digital
    // TRISA: 0 = Salida, 1 = Entrada  
    TRISA = TRISA & 0xEF;     // Bit 4 = 0 (0xEF = 111011110)
    
    // ==========================================================================
    // BUCLE PRINCIPAL - PROGRAMA INFINITO
    // ==========================================================================
    while (1) {
        // Encender LED en RA4
        // Establecer bit 4 de LATA a 1 usando OR lógico
        LATA = LATA | 0x10; // 0x10 = 000100000 (bit 4 = 1)
        __delay_ms(1000); // Esperar 1 segundo
        
        // Apagar LED en RA4  
        // Establecer bit 4 de LATA a 0 usando AND lógico con máscara invertida
        LATA = LATA & 0xEF; // 0xEF = 11101111b (bit 4 = 0)
        __delay_ms(1000); // Esperar 1 segundo
    }
    
    return 0;
}

// =============================================================================
// FIN DEL ARCHIVO
// =============================================================================

