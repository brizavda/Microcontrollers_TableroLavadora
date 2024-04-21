#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 1
#define FIRST_GPIO 2

// Arreglo para definir la secuencia base para todos los ciclos
int secCiclos[5] = {0x01, 0x20, 0x40, 0x04, 0x08}; // Secuencia en forma de "S"


// Función para verificar el estado del botón
bool botonPresionado() {
    static bool ultimoEstado = true;
    bool estadoActual = !gpio_get(BOTON_PRESS);

    if (estadoActual != ultimoEstado) {
        ultimoEstado = estadoActual;
        return estadoActual;
    }

    return false;
}

// Función para cambiar el ciclo actual al presionar el botón
int cambiarCiclo(int ciclo_actual) {
    if (botonPresionado()) {
        // Cambiar al siguiente ciclo al presionar el botón
        ciclo_actual = (ciclo_actual % 3) + 1;
        return ciclo_actual;
    }
    return ciclo_actual;
}

// Función para mostrar el ciclo seleccionado por serial
void mostrarCiclo(int ciclo_actual, int ciclo_anterior) {
    if (ciclo_actual != ciclo_anterior) {
        switch (ciclo_actual) {
            case 1:
                printf("Ciclo seleccionado: %d - Ciclo Normal\n", ciclo_actual);
                break;
            case 2:
                printf("Ciclo seleccionado: %d - Ciclo Delicado\n", ciclo_actual);
                break;
            case 3:
                printf("Ciclo seleccionado: %d - Ciclo Rápido\n", ciclo_actual);
                break;
            default:
                break;
        }
    }
}

int main(){
    stdio_init_all();
    printf("Ciclos de lavadora - Normal(1), Delicado(2), Rápido(3)\n");

    gpio_init(BOTON_PRESS);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);
    gpio_pull_up(BOTON_PRESS);

    // Configurar GPIOs para segmentos del display
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    int ciclo_actual = 1;
    int ciclo_anterior = 0;

    while (true) {
        // Cambiar ciclo si se presiona el botón
        ciclo_actual = cambiarCiclo(ciclo_actual);

        // Mostrar ciclo seleccionado por serial
        mostrarCiclo(ciclo_actual, ciclo_anterior);

        // Ejecutar la secuencia de LED según el ciclo actual
        ejecutarSecuencia(ciclo_actual);

        ciclo_anterior = ciclo_actual; // Actualizar el ciclo anterio
    }
}