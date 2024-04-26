#include <iostream>
#include <stdio.h>
#include "boton_TipoCiclos.h"
#include "../include/pin_list.h"

uint32_t botonCiclos::delay = 2500000; // Tiempo inicial: 250 ms

botonCiclos::botonCiclos():
    tipoCiclos{0x01, 0x20, 0x40, 0x04, 0x08},
    cicloActual(1),
    cicloAnterior(0)
{}

void botonCiclos::inicializar()
{
    for (int gpio = SECOND_GPIO; gpio < SECOND_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BOTON_CICLOS);
    gpio_set_dir(BOTON_CICLOS, GPIO_IN);
    gpio_pull_up(BOTON_CICLOS); // Activar pull-up en el botón
}

int botonCiclos::leer_boton()
{
    return gpio_get(BOTON_PRESS);
}

void botonCiclos::seleccionCiclo()
{

}

