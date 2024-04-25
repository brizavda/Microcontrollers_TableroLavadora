#include "boton_fases.h"
#include "../include/pin_list.h"

// Inicializar la variable estática delay
uint32_t BotonFases::delay = 250000; // Tiempo inicial: 250 ms

BotonFases::BotonFases() {
    fase_actual = 1;
    fase_anterior = 0;
}

void BotonFases::configurarGPIOs() {
    printf("Control de secuencia en display de 7 segmentos\n");

    for (int gpio = SECOND_GPIO; gpio < SECOND_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BOTON_FASES);
    gpio_set_dir(BOTON_FASES, GPIO_IN);
    gpio_pull_up(BOTON_FASES); // Activar pull-up en el botón
}