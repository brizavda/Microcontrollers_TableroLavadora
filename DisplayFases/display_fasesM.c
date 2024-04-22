#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define PRIMER_GPIO 2
#define BOTON_GPIO1 11 // Botón para la animación circular
#define BOTON_GPIO2 12 // Botón para la animación de infinito
#define BOTON_GPIO3 13 // Botón para la animación 'S'

//Arreglos para definir las diferentes secuencias para cada botón
int secLavar[4] = {0x01, 0x22, 0x14, 0x08};                             // Secuencia como en cascada
int secEnjuagar[8] = {0x01, 0x02, 0x40, 0x10, 0x08, 0x04, 0x40, 0x20};  // Secuencia de animación de infinito
int secCentrifugar[6] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20};            // Secuencia de animación circular

//Función para configurar GPIOs

//Función para detectar botones

//Función para cambiar la secuencia

//Función para ejecutar la secuencia

int main(){

}