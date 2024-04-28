#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonTemporizador {
private:
    uint BOTON_GPIO;

public:
    BotonTemporizador(uint gpio);
    void inicializar();
    bool is_pressed();
    void aumentar_tiempo(int& minutos, int& segundos);
};