#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#define FIRST_GPIO 0

#define COMMUN_1 8
#define COMMUN_2 9
#define COMMUN_3 10
#define COMMUN_4 11

int primer_letra = 0x76;

int bits[10] = {
        0x3f,  // 0
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x67   // 9
};

int main() {
    stdio_init_all();

    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);

    }

    for(int gpio = COMMUN_1; gpio <= COMMUN_4; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
    
    gpio_put(COMMUN_4, 1);



    int val = 1;
    while (true) {  


        int32_t mask = primer_letra << FIRST_GPIO;

        gpio_set_mask(mask);
        sleep_ms(250);
        gpio_clr_mask(mask);
    }
}
