#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 4

int main()
{

    stdio_init_all();

    gpio_init(BOTON_PRESS);

    gpio_set_dir(BOTON_PRESS, GPIO_IN);

    gpio_pull_up(BOTON_PRESS);

    int nivel_agua = 0;

    bool cambio_de_nivel = false;

    while (gpio_get(BOTON_PRESS) == 0)
    {
        cambio_de_nivel = true;
    }

    if (cambio_de_nivel == true)
    {
        if (nivel_agua == 0)
        {
            nivel_agua = 1;
        }
        else if (nivel_agua == 1)
        {
            nivel_agua = 2;
        }
        else if (nivel_agua == 2)
        {
            nivel_agua = 3;
        }
        else if (nivel_agua == 3)
        {
            nivel_agua = 4;
        }
        else
        {
            nivel_agua = 1;
        }
    }

    cambio_de_nivel = false;

    if (nivel_agua == 0)
    {
        printf("Selecciona el nivel de agua");
    }
    else if (nivel_agua == 1)
    {
        printf("Nivel de agua bajo");
    }
    else if (nivel_agua == 2)
    {
        printf("Nivel de agua medio");
    }
    else if (nivel_agua == 3)
    {
        printf("Nivel de agua medio alto");
    }
    else
    {
        printf("Nivel de agua alto");
    }
}