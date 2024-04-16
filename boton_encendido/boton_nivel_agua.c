#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#define BOTON_PRESS 4

int main(){

    stdio_init_all();

    gpio_init(BOTON_PRESS);

    gpio_set_dir(BOTON_PRESS, GPIO_IN);

    gpio_pull_up(BOTON_PRESS);

    int main(){

        int nivel_agua;
         


    }



      


}