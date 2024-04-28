#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonNivelAgua {
private:
    uint BOTON_GPIO;
    int nivelAgua;

public:
    BotonNivelAgua(uint gpio);
    void inicializar();
    bool is_pressed();
    int get_nivel();
};