#include "boton_temporizador.h"

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
    if (is_pressed()) {
        // Aumentar el tiempo en 30 segundos al presionar el botón
        segundos += 30;
        if (segundos >= 60) {
            minutos += segundos / 60;
            segundos %= 60;
        }
    }
}