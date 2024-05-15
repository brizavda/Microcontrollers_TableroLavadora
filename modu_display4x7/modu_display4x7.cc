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
    int sleep;
    bool cronometro;
    int temp_crono;

    int segundos_unidades[10] = {
        0x3f, // 0
        0x06, // 1
        0x5b, // 2
        0x4f, // 3
        0x66, // 4
        0x6d, // 5
        0x7d, // 6
        0x07, // 7
        0x7f, // 8
        0x67  // 9
    };

    int segundos_decenas[7] = {
        0x3f, // 0
        0x06, // 1
        0x5b, // 2
        0x4f, // 3
        0x66, // 4
        0x6d, // 5
        0x7d, // 6
    };

    int minutos[10] = {
        0x3f, // 0
        0x06, // 1
        0x5b, // 2
        0x4f, // 3
        0x66, // 4
        0x6d, // 5
        0x7d, // 6
        0x07, // 7
        0x7f, // 8
        0x67  // 9
    };

public:
    modu_display4x7(int, int, int, int, int, int, bool, int);
    void inicializar();
    void establecerPalabraDisplay4x7(int, int, int, int, int, int);
    void establecerCrono4x7(int, int);
    void encenderDisplay4x7();
    void apagarDisplay4x7();
    void leerPalabra(int, int, int, int);
    void ajustarTiempo(int);
    void establecerVal(int);
    void establecerSleep(int);
};

modu_display4x7::modu_display4x7(int _a, int _b, int _c, int _d, int temp, int sleep, bool cronometro, int temp_crono)
{
    palabra[0] = _a;
    palabra[1] = _b;
    palabra[2] = _c;
    palabra[3] = _d;

    this->val = val;
    this->temp = temp;
    val = 0;
    this->sleep = sleep;
    this->cronometro = cronometro;
    this->temp_crono = temp_crono;
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

void modu_display4x7::establecerPalabraDisplay4x7(int _a, int _b, int _c, int _d, int _temp, int _sleep)
{

    leerPalabra(_a, _b, _c, _d);
    ajustarTiempo(_temp);
    val = 0;
    establecerSleep(_sleep);
    encenderDisplay4x7();
}

void modu_display4x7::establecerCrono4x7(int _temp, int _sleep)
{

    int segundos_uni = 0, segundos_dec = 0, minut = 0;
    minut = temp_crono / 100;
    cout << minut;
    temp_crono = temp_crono % 100;
    segundos_dec = temp_crono / 10;
    cout << segundos_dec;
    temp_crono = temp_crono % 10;
    segundos_uni = temp_crono;
    cout << segundos_uni;

    ajustarTiempo(_temp);
    val = 0;
    establecerSleep(_sleep);


    bool parar_cronometro = false; 
    while (!parar_cronometro) {
    if (segundos_uni > 0) {
        segundos_uni--;
    } else {
        segundos_uni = 9;
        if (segundos_dec > 0) {
            segundos_dec--;
        } else {
            segundos_dec = 5;
            if (minut > 0) {
                minut--;
            } else {
                parar_cronometro = true; 
            }
        }
    }



        leerPalabra(0x00, minutos[minut], segundos_decenas[segundos_dec], segundos_unidades[segundos_uni]);
        encenderDisplay4x7();
        if(minut == 0 && segundos_dec == 0 && segundos_uni == 0){
            break;
        }
    }
}

void modu_display4x7::leerPalabra(int _a, int _b, int _c, int _d)
{
    palabra[0] = _a;
    palabra[1] = _b;
    palabra[2] = _c;
    palabra[3] = _d;
}

void modu_display4x7::ajustarTiempo(int t)
{
    temp = t;
}

void modu_display4x7::establecerVal(int v)
{
    val = v;
}

void modu_display4x7::encenderDisplay4x7()
{
    for (int i = 0; i <= temp; i++)
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
        sleep_ms(sleep);
        gpio_clr_mask(mask);

        val++;
    }

    val = 0;

    apagarDisplay4x7();
}

void modu_display4x7::apagarDisplay4x7()
{
    leerPalabra(0x00, 0x00, 0x00, 0x00);
    val = 0;
}

void modu_display4x7::establecerSleep(int _sleep)
{
    sleep = _sleep;
}