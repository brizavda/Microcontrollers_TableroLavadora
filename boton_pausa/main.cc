#include <cstdio>
#include "../include/pin_list.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_pausa.h"

int main() {
    stdio_init_all();

    gpio_init(BOTON_START);
    gpio_set_dir(BOTON_START, GPIO_IN);
    gpio_pull_up(BOTON_START);

    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);

    printf("Presiona para iniciar tu ciclo de lavado\n");

    gpio_set_irq_enabled_with_callback(BOTON_START, GPIO_IRQ_EDGE_FALL, true, &botonCallback);

    while (true) {
        tight_loop_contents();
    }

    return 0;
}
