#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO (FIRST_GPIO+7)

/// \tag::hello_gpio[]
int main() {
    // This array converts a number 1-3 to a bit pattern to send to the GPIOs
    int bits[3] = {
        0x06,  // 1
        0x5b,  // 2
        0x4f   // 3
    };
    stdio_init_all();
    printf("Contador de 1 a 3 - Presiona el botón para contar!\n");

    // Inicializar GPIOs para los segmentos del display
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        // Invertimos la salida ya que estamos usando pull-down
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    // Inicializar GPIO para el botón
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    int val = 0;
    while (true) {
        // Incrementar o decrementar el contador según el estado del botón
        // Al presionar el botón, el contador aumenta
        if (!gpio_get(BUTTON_GPIO)) {
            val = (val % 3) + 1;
        }

        // Encender los segmentos correspondientes al número actual en el contador
        int32_t mask = bits[val - 1] << FIRST_GPIO; // -1 porque el array está indexado desde 0

        // Establecer todos los GPIOs a la vez
        gpio_set_mask(mask);
        sleep_ms(250);
        gpio_clr_mask(mask);
    }
}
