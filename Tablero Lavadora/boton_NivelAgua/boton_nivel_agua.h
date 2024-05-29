#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonNivelAgua {
private:
    uint BOTON_GPIO; /**< GPIO utilizado para el botón de nivel de agua. */
    int nivelAgua = 1; /**< Nivel actual de agua (MINIMO, MEDIO, MAXIMO). */
    bool ultima_pulsacion; /**< Estado de la última pulsación del botón. */
    static const int MINIMO = 1; /**< Nivel de agua mínimo. */
    static const int MEDIO = 2; /**< Nivel de agua medio. */
    static const int MAXIMO = 3; /**< Nivel de agua máximo. */

public:
    /**
     * @brief Constructor de la clase BotonNivelAgua.
     * @param gpio Número de GPIO utilizado para el botón: 27
     */
    BotonNivelAgua(uint gpio);

    /**
     * @brief Inicializa el botón de nivel de agua.
     */
    void inicializar();

    /**
     * @brief Verifica si el botón está presionado.
     * @return true si el botón está presionado, false en caso contrario.
     */
    bool is_pressed();

    /**
     * @brief Obtiene el nivel actual de agua.
     * @return Nivel de agua actual (MINIMO, MEDIO, MAXIMO).
     */
    int get_nivel();
};