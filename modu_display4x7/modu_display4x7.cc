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
    int val = 0;
    int sleep = 0;

public:
    modu_display4x7(int[4]);
    void inializar();
    void encenderDisplay4x7();
    void apagarPermanentemente();
    // void leerPalabra();
    /**void prenderDisplay(int);
    void limpiarMascara(int);
    void set_sleep();**/
};

modu_display4x7::modu_display4x7(int *palabra)
{
    for (int i = 0; i < 4; i++) {
        this->palabra[i] = palabra[i];
    }
    this->val = val;
    this->sleep = sleep;
}

void modu_display4x7::inializar()
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
    for (int i = 0; i <= 3; i++)
    {
        if (i == 0)
        {
            gpio_put(COMMUN_1, 0);
            gpio_put(COMMUN_2, 1);
            gpio_put(COMMUN_3, 1);
            gpio_put(COMMUN_4, 1);
        }
        else if (i == 1)
        {
            gpio_put(COMMUN_1, 1);
            gpio_put(COMMUN_2, 0);
            gpio_put(COMMUN_3, 1);
            gpio_put(COMMUN_4, 1);
        }
        else if (i == 2)
        {
            gpio_put(COMMUN_1, 1);
            gpio_put(COMMUN_2, 1);
            gpio_put(COMMUN_3, 0);
            gpio_put(COMMUN_4, 1);
        }
        else if (i == 3)
        {
            gpio_put(COMMUN_1, 1);
            gpio_put(COMMUN_2, 1);
            gpio_put(COMMUN_3, 1);
            gpio_put(COMMUN_4, 0);
        }

        if (val == 4)
        {
            val = 0;
        }
        
        int32_t mask = palabra[val] << FIRST_GPIO;

            gpio_set_mask(mask);
            sleep_ms(sleep);
            gpio_clr_mask(mask);

            val++;
    }
}

/**
void modu_display4x7::prenderDisplay(int val)
{
    int32_t mask = palabra[val] << FIRST_GPIO;
    gpio_set_mask(mask);
}

void modu_display4x7::limpiarMascara(int val){
int32_t mask = palabra[val] << FIRST_GPIO;
    gpio_clr_mask(mask);

}**/
