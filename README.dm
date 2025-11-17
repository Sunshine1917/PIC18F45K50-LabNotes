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
- Da clic en File y Project Properties.
![Imagen de configuración para el bootloader, file y project properties](https://docs.microside.com/~gitbook/image?url=https%3A%2F%2F177299348-files.gitbook.io%2F~%2Ffiles%2Fv0%2Fb%2Fgitbook-x-prod.appspot.com%2Fo%2Fspaces%252FbyV2zAlQAiqg46a3Lr8z%252Fuploads%252FmWA48vgz0NiwtZUS2t0b%252FFILE%2520MPLAB%2520X%2520IDE%2520-%2520PIC18F45K50%2520PIC18F4550%2520MICROSIDE.png%3Falt%3Dmedia%26token%3D1073ea96-9c9a-40bf-ad99-3c55b3c61d9f&width=768&dpr=2&quality=100&sign=c7a1cd6c&sv=2)
- Selecciona Building, marca la casilla Insert unprotected checksum in user ID memory y da clic en Apply
![Imagen de configuración para el bootloader,  marca la casilla Insert unprotected checksum in user ID memory](https://docs.microside.com/~gitbook/image?url=https%3A%2F%2F177299348-files.gitbook.io%2F~%2Ffiles%2Fv0%2Fb%2Fgitbook-x-prod.appspot.com%2Fo%2Fspaces%252FbyV2zAlQAiqg46a3Lr8z%252Fuploads%252FyrbOKxrIOVdxy2iEdn60%252Fimage.png%3Falt%3Dmedia%26token%3Dc8e5d6cc-40a9-450f-aad1-9332e3e0c822&width=768&dpr=2&quality=100&sign=8e5083b2&sv=2)
- Selecciona XC8 Linker, despliega el apartado Option categories: y selecciona Memory model. 
En la sección de ROM ranges escribe 2000-7f00 y da clic en Apply.
![Imagen de configuración para el bootloader,  marca la casilla Insert unprotected checksum in user ID memory](https://docs.microside.com/~gitbook/image?url=https%3A%2F%2F177299348-files.gitbook.io%2F~%2Ffiles%2Fv0%2Fb%2Fgitbook-x-prod.appspot.com%2Fo%2Fspaces%252FbyV2zAlQAiqg46a3Lr8z%252Fuploads%252FeFT9LG1evjpND3m2U9mb%252Fimage.png%3Falt%3Dmedia%26token%3D847ab880-faaa-417a-b29d-996a0b7c6703&width=768&dpr=4&quality=100&sign=6aea3f6&sv=2)
- Despliega nuevamente el apartado Option categories: y selecciona Additional options. En la sección de Codeoffset escribe 2000, da clic en Apply y por último da clic en OK.
![Imagen de configuración para el bootloader,  selecciona Additional options](https://docs.microside.com/~gitbook/image?url=https%3A%2F%2F177299348-files.gitbook.io%2F~%2Ffiles%2Fv0%2Fb%2Fgitbook-x-prod.appspot.com%2Fo%2Fspaces%252FbyV2zAlQAiqg46a3Lr8z%252Fuploads%252FlyKORTPf2jr1vOwK0H6G%252Fimage.png%3Falt%3Dmedia%26token%3D3c21a96a-f0ba-4aad-b605-ce096310d6b3&width=768&dpr=2&quality=100&sign=792ecdaa&sv=2)

## 📂 Contenido  
- Programas en **C** (`main.c`)  
- Ejercicios relacionados con el PIC18F45K50  
- Código documentado para facilitar la comprensión  

## 🤝 Contribuciones  
Este repo está pensado como un espacio colaborativo. Siéntete libre de abrir *issues* o enviar *pull requests* con mejoras, correcciones o nuevas prácticas.  

## ⚡ Nota  
Los códigos aquí compartidos son de carácter educativo y están diseñados para reforzar el aprendizaje.
