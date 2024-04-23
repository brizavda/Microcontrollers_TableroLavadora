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

// Función para inicializar los GPIOs y configurar los botones
void configurarGPIOs() {
    printf("Control de secuencia en display de 7 segmentos\n");

    for (int gpio = PRIMER_GPIO; gpio < PRIMER_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    gpio_init(BOTON_GPIO1);
    gpio_set_dir(BOTON_GPIO1, GPIO_IN);
    gpio_pull_up(BOTON_GPIO1); // Activar pull-up en el botón

    gpio_init(BOTON_GPIO2);
    gpio_set_dir(BOTON_GPIO2, GPIO_IN);
    gpio_pull_up(BOTON_GPIO2); // Activar pull-up en el botón

    gpio_init(BOTON_GPIO3);
    gpio_set_dir(BOTON_GPIO3, GPIO_IN);
    gpio_pull_up(BOTON_GPIO3); // Activar pull-up en el botón
}

//Función para detectar botones
int detectarBotonPresionado(int boton_actual) {
    if (!gpio_get(BOTON_GPIO1)) {
            boton_actual = 1;
        } else if (!gpio_get(BOTON_GPIO2)) {
            boton_actual = 2;
        } else if (!gpio_get(BOTON_GPIO3)) {
            boton_actual = 3;
        }
    return boton_actual;
}
//Función para cambiar la secuencia
int cambiarSecuencia(int boton_previo,int boton_actual, bool ejecutando){
        if (boton_actual != boton_actual) {
            boton_previo = boton_actual;
            ejecutando = false; // Detener la secuencia actual
            while (!gpio_get(boton_actual == 1 ? BOTON_GPIO1 : boton_actual == 2 ? BOTON_GPIO2 : BOTON_GPIO3)) {} // Esperar a que se suelte el botón
        }
        return boton_previo;
    }

//Función para ejecutar la secuencia

int main(){
    stdio_init_all();

    configurarGPIOs();

    int boton_previo = 0; // Variable para rastrear el último botón presionado
    int boton_actual = 0;  // Variable para rastrear el botón actual activo
    bool ejecutando = false;    // Estado del modo de secuencia

    while(true){
        //Función para detectar botones
        detectarBotonPresionado(boton_actual);
        //Función para cambiar la secuencia
        cambiarSecuencia(boton_previo, boton_actual, ejecutando);
        //Función para ejecutar la secuencia

        sleep_ms(100);
    }
}