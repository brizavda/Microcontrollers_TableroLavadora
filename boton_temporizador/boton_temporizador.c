#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_GPIO 2

int main() {
    stdio_init_all();
    printf("Presiona el botón para iniciar el ciclo de lavado\n");

    // Inicializa la salida para el botón
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    int minutos = 0;
    int segundos = 0;

    while (true) {
        if (gpio_get(BUTTON_GPIO) == 0) {
            // Espera hasta que se suelte el botón
            while (gpio_get(BUTTON_GPIO) == 0) {
                sleep_ms(10);
            }
            // Incrementa el tiempo en 30 segundos
            segundos += 30;
            if (segundos >= 60) {
                minutos += segundos / 60;
                segundos %= 60;
            }
            // Muestra el tiempo total y el mensaje
            printf("Tiempo total de ciclo de lavado: %d minutos y %d segundos\n", minutos, segundos);
        }
        sleep_ms(200); // Breve pausa para evitar múltiples incrementos por un solo botón
    }
    return 0;
}
