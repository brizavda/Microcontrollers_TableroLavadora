#include <iostream>
#include <stdio.h>
#include "boton_TipoCiclos.h"
#include "../include/pin_list.h"

#define BOTON_PRESS 26

botonCiclos::botonCiclos()
{
    this->btn_press = btn_press;
    this->ciclos = ciclos;
}

void botonCiclos::inicializar()
{
    stdio_init_all();

    gpio_init(BOTON_PRESS);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);

    gpio_pull_up(BOTON_PRESS);
}

int botonCiclos::leer_boton()
{
    return gpio_get(BOTON_PRESS);
}

void botonCiclos::seleccionCiclo()
{

}

