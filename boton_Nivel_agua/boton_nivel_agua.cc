#include "boton_nivel_agua.h"
#include <cstdio>

BotonNivelAgua::BotonNivelAgua(uint gpio) : BOTON_GPIO(gpio), nivelAgua(MINIMO), ultima_pulsacion(false) {}

void BotonNivelAgua::inicializar() {
    gpio_init(BOTON_GPIO);
    gpio_set_dir(BOTON_GPIO, GPIO_IN);
    gpio_pull_up(BOTON_GPIO);
}

bool BotonNivelAgua::is_pressed() {
    return (gpio_get(BOTON_GPIO) == 0);
}

int BotonNivelAgua::get_nivel() {
    if (is_pressed() && !ultima_pulsacion) {
        // Cambiar entre los niveles de agua al presionar el botón
        switch (nivelAgua) {
            case MINIMO:
                nivelAgua = MEDIO;
                break;
            case MEDIO:
                nivelAgua = MAXIMO;
                break;
            case MAXIMO:
                nivelAgua = MINIMO;
                break;
        }
        
        // Mostrar el nivel de agua seleccionado
        switch (nivelAgua) {
            case MINIMO:
                printf("Nivel de agua seleccionado: Mínimo\n");
                break;
            case MEDIO:
                printf("Nivel de agua seleccionado: Medio\n");
                break;
            case MAXIMO:
                printf("Nivel de agua seleccionado: Máximo\n");
                break;
        }

        // Registrar la última pulsación y esperar un pequeño retardo
        ultima_pulsacion = true;
        sleep_ms(200); // Retardo de 200 milisegundos (ajustar según sea necesario)
    }

    // Si el botón se suelta, actualizar la variable de última pulsación
    if (!is_pressed()) {
        ultima_pulsacion = false;
    }

    // Retornar el nivel actual
    return nivelAgua;
}