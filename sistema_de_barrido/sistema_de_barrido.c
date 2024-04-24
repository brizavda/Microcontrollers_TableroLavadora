#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 0

#define COMMUN_1 7
#define COMMUN_2 8
#define COMMUN_3 9
#define COMMUN_4 10

int primer_letra = 0x76;
int seguna_letra = 0x3f;
int tercer_letra = 0x38;
int cuarta_letra = 0x77;

int palabra[4] = {
    0x76,
    0x3f,
    0x38,
    0x77,
};

int bits[10] = {
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

int main()
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

    int val = 0;
    int sleep = 30;

    while (true)

    {

        if (sleep == 0)
        {
            sleep = 1;
            //sleep = 1;
        }
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

        sleep--;
    }
}
