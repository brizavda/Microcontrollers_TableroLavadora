#include "boton_pausa.h"

BotonPausaInicio::BotonPausaInicio() {
    this->ciclo_iniciado = ciclo_iniciado;
    this->valor = valor;
}

int BotonPausaInicio::leer_boton() {
    return gpio_get(BOTON_START);
}

void BotonPausaInicio::iniciar_o_pausar_ciclo() {
    valor = leer_boton();
    if (valor == 0) {
        ciclo_iniciado = !ciclo_iniciado;
    }
    actualizar_led();
}

void BotonPausaInicio::actualizar_led() {
    if (ciclo_iniciado) {
        gpio_put(LED_PIN_2, 1);
    } else {
        gpio_put(LED_PIN_2, 0);
    }
}

void BotonPausaInicio::inicializar() {
    stdio_init_all();

    gpio_init(LED_PIN_2);
    gpio_init(BOTON_START);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);
    gpio_set_dir(BOTON_START, GPIO_IN);
    gpio_pull_up(BOTON_START);
}

bool BotonPausaInicio::get_estado_ciclo() {
    if (ciclo_iniciado) {
        printf("Ciclo iniciado\n");
    } else {
        printf("Ciclo pausado\n");
    }
    return ciclo_iniciado;
}
