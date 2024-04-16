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

    while (true)
    {
        
        while (gpio_get(BOTON_PRESS) == 0)
        {
            cambio_de_nivel = true;
            sleep_ms(100);
        }

        if (cambio_de_nivel == true)
        {
            if (nivel_agua == 0)
            {
                nivel_agua = 1;
                sleep_ms(100);
            }
            else if (nivel_agua == 1)
            {
                nivel_agua = 2;
                sleep_ms(100);
            }
            else if (nivel_agua == 2)
            {
                nivel_agua = 3;
                sleep_ms(100);
            }
            else if (nivel_agua == 3)
            {
                nivel_agua = 4;
                sleep_ms(100);
            }
            else
            {
                nivel_agua = 1;
                sleep_ms(100);
            }
        }

        cambio_de_nivel = false;
        sleep_ms(50);

        if (nivel_agua == 0)
        {
            printf("Selecciona el nivel de agua\n");
            sleep_ms(50);
        }
        else if (nivel_agua == 1)
        {
            printf("Nivel de agua bajo\n");
            sleep_ms(50);
        }
        else if (nivel_agua == 2)
        {
            printf("Nivel de agua medio\n");
            sleep_ms(50);
        }
        else if (nivel_agua == 3)
        {
            printf("Nivel de agua medio alto\n");
            sleep_ms(50);
        }
        else
        {
            printf("Nivel de agua alto\n");
            sleep_ms(50);
        }
    }
}