#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO (FIRST_GPIO + 7)

// Segment bit patterns for digits 0-9
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

void mostrar_numero(int num) {
    int32_t mask = bits[num] << FIRST_GPIO;
    gpio_set_mask(mask);
}

int main() {
    stdio_init_all();
    printf("Encendiendo el display 7 segmentos. Presiona el botón para que el temporizador aumente\n");

    // Inicializa las salidas para el 7 segmentos
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    // Inicializa la salida para el botón
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    int count = 0; // Inicialmente mostrar el número 0 en el display

    while (true) {
        mostrar_numero(count);
        if (gpio_get(BUTTON_GPIO) == 0) {
            // Incrementa el contador y muestra el número correspondiente
            count++;
            if (count > 9) {
                count = 0; // Vuelve al 0 si se llega al 9
            }
            sleep_ms(200); // Breve pausa para evitar múltiples incrementos por un solo botón
        }
    }
}
