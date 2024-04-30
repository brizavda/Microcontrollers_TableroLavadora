#include "boton_temporizador.h"
#include <cstdio>

BotonTemporizador::BotonTemporizador(uint gpio) : BOTON_GPIO(gpio) {}

void BotonTemporizador::inicializar() {
    gpio_init(BOTON_GPIO);
    gpio_set_dir(BOTON_GPIO, GPIO_IN);
    gpio_pull_up(BOTON_GPIO);
}

bool BotonTemporizador::is_pressed() {
    return (gpio_get(BOTON_GPIO) == 0);
}

void BotonTemporizador::aumentar_tiempo(int& minutos, int& segundos) {
    if (is_pressed() && !ultima_pulsacion) {
        // Aumentar el tiempo en 30 segundos al presionar el botón
        segundos += 30;
        if (segundos >= 60) {
            minutos += segundos / 60;
            segundos %= 60;
        }

        // Mostrar el tiempo del temporizador después de aumentarlo
        printf("Tiempo del temporizador: %02d:%02d\n", minutos, segundos);

        // Registrar la última pulsación y esperar un pequeño retardo
        ultima_pulsacion = true;
        sleep_ms(200); // Retardo de 200 milisegundos (ajustar según sea necesario)
    }

    // Si el botón se suelta, actualizar la variable de última pulsación
    if (!is_pressed()) {
        ultima_pulsacion = false;
    }
}