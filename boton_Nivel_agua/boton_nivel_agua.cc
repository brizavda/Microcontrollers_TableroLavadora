#include "boton_nivel_agua.h"

BotonNivelAgua::BotonNivelAgua(uint gpio) : BOTON_GPIO(gpio), nivelAgua(1) {}

void BotonNivelAgua::inicializar() {
    gpio_init(BOTON_GPIO);
    gpio_set_dir(BOTON_GPIO, GPIO_IN);
    gpio_pull_up(BOTON_GPIO);
}

bool BotonNivelAgua::is_pressed() {
    return (gpio_get(BOTON_GPIO) == 0);
}

int BotonNivelAgua::get_nivel() {
    if (is_pressed()) {
        // Cambiar entre los niveles de agua al presionar el botón
        nivelAgua = (nivelAgua % 3) + 1;
        // Retornar el nivel actual
        return nivelAgua;
    }
    // Si no se presiona, retorna el nivel actual sin cambiarlo
    return nivelAgua;
}