#ifndef BOTON_PAUSA_INICIO_H
#define BOTON_PAUSA_INICIO_H

#include <iostream> // @brief Incluye la biblioteca estándar de entrada y salida.
#include <vector> // @brief Incluye la biblioteca para utilizar vectores.
#include <stdio.h> // @brief Incluye la biblioteca estándar de entrada y salida.
#include "pico/stdlib.h" // @brief Incluye la biblioteca de pico estándar.
#include "hardware/gpio.h" // @brief Incluye la biblioteca de GPIO del hardware.
#include "../include/pin_list.h" // @brief Incluye el archivo de encabezado que contiene la lista de pines utilizados.

using namespace std; // @brief Utiliza el espacio de nombres estándar.

class BotonPausaInicio { // @brief Declaración de la clase BotonPausaInicio.
private:
    bool ciclo_iniciado = false; // @brief Variable privada para almacenar el estado del ciclo (iniciado o pausado).
    int valor = 1; // @brief Variable privada para almacenar el valor del botón.

public:
    BotonPausaInicio(); // @brief Constructor de la clase.
    int leer_boton(); // @brief Método para leer el estado del botón de inicio/pausa.
    void iniciar_o_pausar_ciclo(); // @brief Método para iniciar o pausar el ciclo.
    void actualizar_led(); // @brief Método para actualizar el estado del LED.
    void inicializar(); // @brief Método para inicializar los pines GPIO y la UART.
    bool get_estado_ciclo(); // @brief Método para obtener el estado actual del ciclo.
};

#endif /* BOTON_PAUSA_INICIO_H */ // @brief Fin de la declaración de preprocesador #ifndef y #define.
