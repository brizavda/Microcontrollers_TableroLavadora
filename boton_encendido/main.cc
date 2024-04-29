#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_encendido.h"
using namespace std;

int main(){

    boton_encendido boton = boton_encendido();
    boton.inicializar();

    while(true){
        
        boton.get_estado_lavadora();
        boton.encender_o_apagar_lavadora();
        sleep_ms(500);
    }


    
    return 0; 
}