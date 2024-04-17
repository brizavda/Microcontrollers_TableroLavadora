# Microcontrollers_TableroLavadora
El objetivo de este proyecto es crear un tablero de lavadora

Control de Lavadora con Raspberry Pi Pico W
Este archivo README proporciona una descripción detallada del código que controla una lavadora utilizando una Raspberry Pi Pico W. El código implementa la funcionalidad de encendido y apagado de la lavadora mediante un botón conectado a la Pi Pico.

Materiales Necesarios:
1 Push Button (Botón pulsador) de 4 pines
1 Protoboard
1 Raspberry Pi Pico W
1 LED de color verde
2 resistencias de 68 ohms
4 cables macho-macho
Estos materiales son fundamentales para la implementación del control de la lavadora utilizando la Raspberry Pi Pico W. Asegúrate de tener todos los elementos antes de comenzar el proyecto.

Conexión

[![Glorious-Maimu-Duup.png](https://i.postimg.cc/5N2JpccD/Glorious-Maimu-Duup.png)](https://postimg.cc/Z02XKM5L)

Descripción del Código
El código está escrito en C y utiliza las bibliotecas estándar de la Raspberry Pi Pico y las bibliotecas específicas de hardware para controlar los pines GPIO.

Inicialización de Pines
Antes de utilizar los pines GPIO para entrada o salida, es necesario inicializarlos. Esto se hace utilizando la función gpio_init, que configura el pin para su uso.


gpio_init(LED_PIN);
gpio_init(BOTON_PRESS);
Configuración de Dirección de Pines
Una vez inicializados, los pines GPIO deben configurarse para indicar si serán utilizados como entrada o salida. La función gpio_set_dir se encarga de esta tarea.


gpio_set_dir(LED_PIN, GPIO_OUT);
gpio_set_dir(BOTON_PRESS, GPIO_IN);
En este código, el pin del LED se configura como salida (GPIO_OUT), lo que permite que se pueda escribir un valor lógico alto o bajo en él para encender o apagar el LED. Mientras que el pin del botón se configura como entrada (GPIO_IN), lo que permite leer el estado del botón.

Activación de Resistencia Pull-Up
En muchos casos, especialmente al trabajar con botones o interruptores, es importante evitar flotaciones en el estado del pin cuando no hay una señal clara. Esto se logra activando una resistencia pull-up o pull-down interna en el pin. La función gpio_pull_up activa la resistencia pull-up en el pin especificado.


gpio_pull_up(BOTON_PRESS);
Activar la resistencia pull-up en el pin del botón asegura que, cuando no se está presionando el botón, el pin se mantenga en un estado lógico alto.

Uso
Conecte la Raspberry Pi Pico W a la lavadora según las instrucciones provistas.

Compile el código y cargue el programa en la Raspberry Pi Pico.

Una vez que el programa esté en ejecución, puede controlar el encendido y apagado de la lavadora presionando el botón conectado a la Pi Pico.

Notas Adicionales
Estas funciones (gpio_init, gpio_set_dir, gpio_pull_up) son parte de las bibliotecas proporcionadas por la Raspberry Pi Pico SDK y se utilizan para interactuar directamente con los pines GPIO de la Pi Pico.

La correcta inicialización y configuración de los pines GPIO es crucial para un funcionamiento confiable del sistema, especialmente cuando se trabaja con dispositivos externos como botones, LEDs u otros componentes.

Este README proporciona una visión general del código y su funcionalidad, así como una explicación de las funciones utilizadas para la manipulación de pines GPIO. Para obtener más detalles sobre la implementación específica, consulte los comentarios en el código fuente.
