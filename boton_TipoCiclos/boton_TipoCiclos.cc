#include <iostream>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 26

class botonCiclos{
    private:
        bool btn_press = false;
        int ciclos = 0;

    public:
        botonCiclos()
        leer_boton()
}

int botonCiclos::leer_boton()
{
    return gpio_get(BOTON_PRESS);
}