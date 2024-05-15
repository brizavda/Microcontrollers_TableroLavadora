#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "modu_boton_encendido.h"
#include "../modu_display4x7/modu_display4x7.cc"

using namespace std;

int main()
{
    boton_encendido boton = boton_encendido();
    boton.inicializar();

    modu_display4x7 display = modu_display4x7(0x00, 0x00, 0x00, 0x00, 1, 1000, true, 123);
    display.inicializar();

    bool encendida = false; 

    while (true)
    {
        while(!encendida && gpio_get(BOTON_ON_OFF) == 1){
            display.restablecerDisplay4x7(0x00, 0x3f, 0x71, 0x71, 3, 1);
            if(gpio_get(BOTON_ON_OFF) == 0){
                encendida = true;
            }

        }
        boton.encender_o_apagar_lavadora();

        if (boton.get_estado_lavadora() == true)
        {
            display.restablecerDisplay4x7(0x76, 0x3f, 0x38, 0x77, 50, 1);
            for (int i = 0; i <= 250; i++)
            {
                display.restablecerDisplay4x7(0xef, 0xef, 0xef, 0xef, 2, 1);
            }

        }
        else
        {
            display.restablecerDisplay4x7(0x00, 0x7f, 0x6e, 0x79, 1000, 50);
            encendida = false;
        }
        sleep_ms(100);
    }

    return 0;
}