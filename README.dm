🚀  PIC18F45K50-LabNotes

Este repositorio contiene prácticas realizadas en **MPLAB X IDE** utilizando el microcontrolador **PIC18F45K50**.  
El desarrollo se llevó a cabo con la tarjeta **X-TRAINER DIP R3**, enfocándose en proyectos y ejemplos vistos en la materia de **Arquitectura de Computadoras** de la **Facultad
de Ciencias de la Computación**.  

## 🎯 Objetivo  
El propósito de este repositorio es apoyar a estudiantes de la FCC que cursan la asignatura de Arquitectura de Computadoras, proporcionando ejemplos de código en `main.c` 
que pueden servir como referencia para comprender mejor el uso del PIC18F45K50 y el desarrollo de prácticas.  

## Software 
- MPLAB X IDE
- Compilador XC8
- X-TRAINER Suite
- Windows 11 o posterior

## MPLAB Code Configurator
Realiza los siguientes pasos para configurar el bootloader y poder programar la tarjeta X-TRAINER

- Da clic en **File** y **Project Properties**.

![Imagen de configuración para el bootloader, file y project properties](Imagenes/Imagen_1.png)

- Selecciona **Building**, marca la casilla **Insert unprotected checksum in user ID memory** y da clic en **Apply**

![Imagen de configuración para el bootloader, marca la casilla Insert unprotected checksum in user ID memory](Imagenes/Imagen_2.png)

- Selecciona **XC8 Linker**, despliega el apartado **Option categories:** y selecciona **Memory model**. 
En la sección de **ROM ranges** escribe **2000-7f00** y da clic en **Apply**.

![Imagen de configuración para el bootloader, marca la casilla Insert unprotected checksum in user ID memory](Imagenes/Imagen_3.png)

- Despliega nuevamente el apartado **Option categories:** y selecciona **Additional options**. En la sección de **Codeoffset** escribe **2000**, da clic en **Apply** y por último da clic en **OK**.

![Imagen de configuración para el bootloader, selecciona Additional options](Imagenes/Imagen_4.png)

## 📂 Contenido  
- Programas en **C** (`main.c`)  
- Ejercicios relacionados con el PIC18F45K50  
- Código documentado para facilitar la comprensión  

## 🤝 Contribuciones  
Este repo está pensado como un espacio colaborativo. Siéntete libre de abrir *issues* o enviar *pull requests* con mejoras, correcciones o nuevas prácticas.  

## ⚡ Nota  
Los códigos aquí compartidos son de carácter educativo y están diseñados para reforzar el aprendizaje.
