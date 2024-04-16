#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 4

int main(){

    stdio_init_all();
    printf("Ciclos de lavadora - Normal(1), Delicado(2), Rápido(3)\n");

    gpio_init(BOTON_PRESS);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);
    gpio_pull_up(BOTON_PRESS);

    int ciclos = 0;
    
    bool button_pressed = false;

    while(true){
        while (gpio_get(BOTON_PRESS) == 0)
        {
            cambio_de_nivel = true;
            sleep_ms(100);
        }
    }

}