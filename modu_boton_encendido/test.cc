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
   
    modu_display4x7 display_on= modu_display4x7(0x76, 0x3F, 0x38, 0x77, 1000);
    display_on.inicializar();
    
    modu_display4x7 display_off= modu_display4x7(0x00, 0x7f, 0x6e, 0x79, 1000);
    display_off.inicializar();


    while (true)
    {

        boton.get_estado_lavadora();
        boton.encender_o_apagar_lavadora();
        if(boton.get_estado_lavadora() == true){
            display_on.encenderDisplay4x7();
        } else{
            display_off.encenderDisplay4x7();
            

        }
        sleep_ms(1000);
    }

    return 0;
}