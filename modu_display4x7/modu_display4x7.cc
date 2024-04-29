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
    int temp = 0;

public:
    modu_display4x7(int, int, int, int, int);
    void inicializar();
    void leerPalabra(int, int, int, int);
    void ajustarTiempo(int);
    void encenderDisplay4x7();
    void apagarDisplay4x7();
};

modu_display4x7::modu_display4x7(int a, int b, int c, int d, int temp)
{
    palabra[0] = d;
    palabra[1] = a;
    palabra[2] = b;
    palabra[3] = c;

    this->val = val;
    this->temp = temp;
    val = 0;
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

void modu_display4x7::leerPalabra(int a, int b, int c, int d)
{
    palabra[0] = d;
    palabra[1] = a;
    palabra[2] = b;
    palabra[3] = c;
}

void modu_display4x7::ajustarTiempo(int a)
{
    temp = a;
}

void modu_display4x7::encenderDisplay4x7()
{

    for (int i = 0; i <= temp * 3; i++)
    {

        if (val == 4)
        {
            val = 0;
        }

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

        int32_t mask = palabra[val] << FIRST_GPIO;

        gpio_set_mask(mask);
        sleep_ms(1);
        gpio_clr_mask(mask);

        val++;
    }

    apagarDisplay4x7();
}

void modu_display4x7::apagarDisplay4x7()

{
    leerPalabra(0x00, 0x00, 0x00, 0x00);
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
