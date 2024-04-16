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

int main(){
    stdio_init_all();
    
    printf("Control de secuencia en display de 7 segmentos\n");

    // Configurar GPIOs para segmentos y botones
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

    int boton_previo = 0; // Variable para rastrear el último botón presionado
    int boton_actual = 0;  // Variable para rastrear el botón actual activo
    bool ejecutando = false;    // Estado del modo de secuencia
}