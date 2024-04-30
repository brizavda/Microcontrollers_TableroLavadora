#include "boton_pausa.h" // Incluye el archivo de encabezado que contiene las definiciones de la clase BotonPausaInicio y las constantes utilizadas.

BotonPausaInicio::BotonPausaInicio() {
    // Constructor de la clase BotonPausaInicio. 
    // Aquí inicializamos las variables miembro de la clase.
    this->ciclo_iniciado = ciclo_iniciado; // Esto no inicializa la variable ciclo_iniciado, parece ser un error.
    this->valor = valor; // Esto tampoco inicializa la variable valor.
}

int BotonPausaInicio::leer_boton() {
    // Método para leer el estado del botón de inicio/pausa.
    return gpio_get(BOTON_START); // Devuelve el estado del botón.
}

void BotonPausaInicio::iniciar_o_pausar_ciclo() {
    // Método para iniciar o pausar el ciclo dependiendo del estado del botón.
    valor = leer_boton(); // Lee el estado actual del botón.
    if (valor == 0) {
        ciclo_iniciado = !ciclo_iniciado; // Cambia el estado del ciclo (iniciado/pausado) si se presiona el botón.
    }
    actualizar_led(); // Actualiza el estado del LED según el estado del ciclo.
}

void BotonPausaInicio::actualizar_led() {
    // Método para actualizar el estado del LED según el estado del ciclo.
    if (ciclo_iniciado) {
        gpio_put(LED_PIN_2, 1); // Enciende el LED si el ciclo está iniciado.
    } else {
        gpio_put(LED_PIN_2, 0); // Apaga el LED si el ciclo está pausado.
    }
}

void BotonPausaInicio::inicializar() {
    // Método para inicializar los pines GPIO y la UART.
    stdio_init_all(); // Inicializa la UART para imprimir mensajes de depuración.

    gpio_init(LED_PIN_2); // Inicializa el pin del LED como salida.
    gpio_init(BOTON_START); // Inicializa el pin del botón de inicio/pausa como entrada.
    gpio_set_dir(LED_PIN_2, GPIO_OUT); // Configura el pin del LED como salida.
    gpio_set_dir(BOTON_START, GPIO_IN); // Configura el pin del botón como entrada.
    gpio_pull_up(BOTON_START); // Habilita la resistencia pull-up en el pin del botón.
}

bool BotonPausaInicio::get_estado_ciclo() {
    // Método para obtener y mostrar el estado actual del ciclo.
    if (ciclo_iniciado) {
        printf("Ciclo iniciado\n"); // Imprime un mensaje si el ciclo está iniciado.
    } else {
        printf("Ciclo pausado\n"); // Imprime un mensaje si el ciclo está pausado.
    }
    return ciclo_iniciado; // Devuelve el estado del ciclo.
}
