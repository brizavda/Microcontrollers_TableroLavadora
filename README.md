
## Documentación de Proyecto: Botón de encendido y apaado para Lavadora con Raspberry Pi Pico

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
Conecte la Raspberry Pi Pico W a la protoboard según las instrucciones provistas.

Compile el código y cargue el programa en la Raspberry Pi Pico.

Una vez que el programa esté en ejecución, puede controlar el encendido y apagado de la lavadora presionando el botón conectado a la Pi Pico.

Notas Adicionales
Estas funciones (gpio_init, gpio_set_dir, gpio_pull_up) son parte de las bibliotecas proporcionadas por la Raspberry Pi Pico SDK y se utilizan para interactuar directamente con los pines GPIO de la Pi Pico.

La correcta inicialización y configuración de los pines GPIO es crucial para un funcionamiento confiable del sistema, especialmente cuando se trabaja con dispositivos externos como botones, LEDs u otros componentes.

Este README proporciona una visión general del código y su funcionalidad, así como una explicación de las funciones utilizadas para la manipulación de pines GPIO. Para obtener más detalles sobre la implementación específica, consulte los comentarios en el código fuente.


## Documentación de Proyecto: Botón de Nivel de Agua para Lavadora con Raspberry Pi Pico
Resumen
Este proyecto presenta la implementación de un sensor de nivel de agua para una lavadora utilizando un Raspberry Pi Pico junto con un botón pulsador. El sensor detecta diferentes niveles de agua y proporciona una salida visual mediante mensajes en la consola, lo que permite monitorear el nivel de agua durante el ciclo de lavado.

Materiales Necesarios
1 Raspberry Pi Pico W
1 Botón pulsador de 4 pines
1 Protoboard
1 Resistencia de 68 ohms
2 Cables macho-macho

Conexiones

[![image.png](https://i.postimg.cc/7hgXgRFx/image.png)](https://postimg.cc/Mfpyw9Z4)

Compilación e Instalación
Descargar el código fuente proporcionado y guardarlo en la Raspberry Pi Pico.

Compilar el código utilizando un entorno de desarrollo compatible con C/C++.

Transferir el archivo binario compilado a la Raspberry Pi Pico.

Ejecutar el programa en la Raspberry Pi Pico.

Funcionamiento del Código
El código proporcionado en C controla el comportamiento del botón pulsador y la visualización de los diferentes niveles de agua en la consola. Está diseñado para simular los niveles de agua en una lavadora durante el ciclo de lavado. A continuación, se explica la función de algunas partes clave del código:

stdio_init_all(): Inicializa la funcionalidad estándar de entrada/salida para permitir el uso de funciones como printf() para la salida en la consola.

gpio_init(BOTON_PRESS): Inicializa el pin GPIO conectado al botón pulsador.

gpio_set_dir(BOTON_PRESS, GPIO_IN): Configura el pin GPIO como entrada.

gpio_pull_up(BOTON_PRESS): Habilita la resistencia de pull-up interna en el pin GPIO para asegurar un nivel lógico alto cuando el botón no está presionado.

gpio_get(BOTON_PRESS): Lee el estado del pin GPIO conectado al botón, devolviendo 1 si está presionado y 0 si no lo está.

Uso del Programa
Compile el código utilizando un compilador C/C++ compatible.

Conecte la Raspberry Pi Pico al protoboard según las conexiones especificadas.

Alimente la Raspberry Pi Pico y asegúrese de que esté funcionando correctamente.

Ejecute el programa en la Raspberry Pi Pico.

Durante el ciclo de lavado, presione el botón para simular diferentes niveles de agua en la lavadora.

Observe los mensajes en la consola que indican el nivel de agua detectado durante el ciclo.

Conclusiones
Este proyecto demuestra cómo utilizar un Raspberry Pi Pico junto con un botón pulsador para crear un sensor de nivel de agua simple pero efectivo para una lavadora. La capacidad de monitorear los niveles de agua durante el ciclo de lavado puede ser útil para garantizar un funcionamiento eficiente y adecuado de la lavadora. Se puede expandir este proyecto para incluir más funcionalidades, como el control automático del ciclo de lavado en función del nivel de agua detectado.

