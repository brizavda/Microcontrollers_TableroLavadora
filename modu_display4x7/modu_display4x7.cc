#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/lista_pin.h"

using namespace std;

class modu_display4x7
{
private:
    int palabra[4]; 
    int val;
    int sleep;

public:
    modu_display4x7(int, int, int, int);
    void inicializar(); 
    void encenderDisplay4x7();
};

modu_display4x7::modu_display4x7(int a, int b, int c, int d)
{
    palabra[0] = a;
    palabra[1] = b;
    palabra[2] = c;
    palabra[3] = d;

    val = 0; 
    sleep = 0; 
}

void modu_display4x7::inicializar() 
{
    stdio_init_all();

    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    for (int gpio = COMMUN_1; gpio <= COMMUN_4; gpio++)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
}

void modu_display4x7::encenderDisplay4x7()
{
    if (val == 0)
    {
        gpio_put(COMMUN_1, 0);
        gpio_put(COMMUN_2, 1);
        gpio_put(COMMUN_3, 1);
        gpio_put(COMMUN_4, 1);
    }
    else if (val == 1)
    {
        gpio_put(COMMUN_1, 1);
        gpio_put(COMMUN_2, 0);
        gpio_put(COMMUN_3, 1);
        gpio_put(COMMUN_4, 1);
    }
    else if (val == 2)
    {
        gpio_put(COMMUN_1, 1);
        gpio_put(COMMUN_2, 1);
        gpio_put(COMMUN_3, 0);
        gpio_put(COMMUN_4, 1);
    }
    else if (val == 3)
    {
        gpio_put(COMMUN_1, 1);
        gpio_put(COMMUN_2, 1);
        gpio_put(COMMUN_3, 1);
        gpio_put(COMMUN_4, 0);
    }

    if (val == 3)
    {
        val = 0;
    }
    else
    {
        val++; 
    }

    int32_t mask = palabra[val] << FIRST_GPIO;

    gpio_set_mask(mask);
    sleep_ms(1);
    gpio_clr_mask(mask);
}

