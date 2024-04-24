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
        void inicializar()
        int leer_boton()
        void seleccionCiclo()
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

