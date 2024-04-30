#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonTemporizador {
private:
    uint BOTON_GPIO; /**< GPIO utilizado para el botón del temporizador. */
    bool ultima_pulsacion; /**< Estado de la última pulsación del botón. */

public:
    /**
     * @brief Constructor de la clase BotonTemporizador.
     * @param gpio Número de GPIO utilizado para el botón: 28
     */
    BotonTemporizador(uint gpio);

    /**
     * @brief Inicializa el botón del temporizador.
     */
    void inicializar();

    /**
     * @brief Verifica si el botón está presionado.
     * @return true si el botón está presionado, false en caso contrario.
     */
    bool is_pressed();

    /**
     * @brief Aumenta el tiempo del temporizador en 30 segundos.
     * @param minutos Referencia al número de minutos del temporizador.
     * @param segundos Referencia al número de segundos del temporizador.
     */
    void aumentar_tiempo(int& minutos, int& segundos);
};
