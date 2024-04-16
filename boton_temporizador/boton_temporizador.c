#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define BUTTON_PIN 12
#define TIMER_DURATION_SECONDS 10

volatile uint32_t timer_count = 0;

void button_callback(uint gpio, uint32_t events) {
    if (gpio == BUTTON_PIN && (events & GPIO_IRQ_EDGE_FALL)) {
        timer_count++;
        printf("El tiempo a incrementado %d minutos\n", timer_count);
    }
}

int main() {
    stdio_init_all();

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        // Do something while waiting, if needed
        sleep_ms(1000); // Sleep for 1 second
        // Check if timer has reached the desired duration
        if (timer_count >= TIMER_DURATION_SECONDS) {
            printf("El ciclo de lavado a terminado!\n");
            break;
        }
    }

    return 0;
}
