#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 1
#define FIRST_GPIO 2

// Arreglo para definir la secuencia base para todos los ciclos
int secCiclos[5] = {0x01, 0x20, 0x40, 0x04, 0x08}; // Secuencia en forma de "S"


int main(){
    stdio_init_all();
    printf("Ciclos de lavadora - Normal(1), Delicado(2), Rápido(3)\n");

    gpio_init(BOTON_PRESS);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);
    gpio_pull_up(BOTON_PRESS);

    // Configurar GPIOs para segmentos del display
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    int ciclo_actual = 1;
    int ciclo_anterior = 0;

    while (true) {
        // Cambiar ciclo si se presiona el botón
        ciclo_actual = cambiarCiclo(ciclo_actual);

        // Mostrar ciclo seleccionado por serial
        mostrarCiclo(ciclo_actual, ciclo_anterior);

        // Ejecutar la secuencia de LED según el ciclo actual
        ejecutarSecuencia(ciclo_actual);

        ciclo_anterior = ciclo_actual; // Actualizar el ciclo anterio
    }
}