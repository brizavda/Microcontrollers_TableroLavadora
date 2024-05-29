#define UART_TX_PIN 16
#define UART_RX_PIN 17

#define UART_ID uart0
#define BAUD_RATE 9600

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"

#include "../boton_TipoCiclos/boton_TipoCiclos.cc"
#include "../boton_Encendido/boton_Encendido.h"
#include "../boton_Fases/boton_Fases.cc"
#include "../boton_InicioPausa/boton_InicioPausa.cc"
#include "../boton_NivelAgua/boton_NivelAgua.cc"
#include "../boton_Temporizador/boton_Temporizador.cc"
#include "../display4x7/display4x7.h"
#include "../include/pin_list.h"

int main()
{
    uint8_t cmd = 0;

    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    boton_encendido botonEncendido = boton_encendido();
    botonEncendido.inicializar();

    BotonPausaInicio boton = BotonPausaInicio();
    boton.inicializar();

    modu_display4x7 display = modu_display4x7();
    display.inicializar();

    BotonTemporizador botonTemporizador(BOTON_TEMP);
    botonTemporizador.inicializar();

    BotonNivelAgua botonNivelAgua(BOTON_LVL_AGUA);
    botonNivelAgua.inicializar();

    BotonCiclos botonCiclos;
    botonCiclos.configurarGPIOs();

    BotonFases botonFases = BotonFases();
    botonFases.configurarGPIOs();

    int Fase = 0;
    int Ciclo = 0;
    int Agua = 0;
    int Temp = 0;
    int Minutos = 0;
    int tiempo = 0;
    bool configuracion = true;
    bool trabajar = false;
    bool encendida = true;

    int numeros[10] = {
        0x3f, // 0
        0x06, // 1
        0x5b, // 2
        0x4f, // 3
        0x66, // 4
        0x6d, // 5
        0x7d, // 6
        0x07, // 7
        0x7f, // 8
        0x67  // 9
    };

    while (true)
    {
        botonEncendido.get_estado_lavadora();

        botonEncendido.encender_o_apagar_lavadora();
        sleep_ms(500);

        if (botonEncendido.get_estado_lavadora()) // Envial señal blink
        {

            Minutos = 0;
            tiempo = 0;
            trabajar = false;
            configuracion = true;
            Fase = 0;
            Ciclo = 0;
            Agua = 0;
            Temp = 0;

            if (encendida == true)
            {
                cmd = 1;
                uart_putc(UART_ID, cmd + 0x30);
                sleep_ms(1000);
                display.establecerPalabraDisplay4x7(0x76, 0x3F, 0x38, 0x77, 500, 5);
                encendida = false;
            }

            while (configuracion == true && botonEncendido.get_estado_lavadora() == true)
            {
                cmd = 6;
                uart_putc(UART_ID, cmd + 0x30);
                sleep_ms(50);
                botonEncendido.encender_o_apagar_lavadora();
                botonEncendido.get_estado_lavadora();

                display.establecerPalabraDisplay4x7(0x39, 0x5c, 0x54, 0x71, 1000, 1);
                sleep_ms(10);

                if (botonFases.botonFasesPresionado())
                {
                    for (int i = 0; i <= 1000; i++)
                    {
                        botonFases.cambiarFase();
                        sleep_ms(1);
                    }

                    Fase = botonFases.mostrarFase();

                    botonFases.ejecutarSecuencia();

                    for (int i = 0; i <= 0; i++)
                    {
                        botonFases.ejecutarSecuencia();
                    }
                    sleep_ms(10);
                    display.establecerPalabraDisplay4x7(0x71, 0x00, 0x00, numeros[Fase], 3000, 1);
                    sleep_ms(50);
                }
                else if (botonCiclos.botonCiclosPresionado())
                {
                    for (int i = 0; i <= 1000; i++)
                    {
                        botonCiclos.cambiarCiclo();
                        sleep_ms(1);
                    }

                    Ciclo = botonCiclos.mostrarCiclo();
                    for (int i = 0; i <= 2; i++)
                    {
                        botonCiclos.ejecutarSecuencia();
                        sleep_ms(1);
                    }

                    sleep_ms(50);
                    display.establecerPalabraDisplay4x7(0x39, 0x00, 0x00, numeros[Ciclo], 3000, 1);
                }
                else if (botonNivelAgua.is_pressed())
                {
                    for (int i = 0; i <= 1000; i++)
                    {
                        Agua = botonNivelAgua.get_nivel();
                        sleep_ms(1);
                    }

                    display.establecerPalabraDisplay4x7(0x77, 0x00, 0x00, numeros[Agua], 3000, 1);
                }
                else if (botonTemporizador.is_pressed())
                {
                    for (int i = 0; i <= 0; i++)
                    {
                        Temp = botonTemporizador.aumentar_tiempo();
                        sleep_ms(1);
                    }

                    Minutos = Temp / 30;

                    if (Temp == 5430)
                    {
                        Temp = 0;
                    }
                    else if (Temp >= 600)
                    {
                        if (Minutos % 2 == 0)
                        {
                            display.establecerPalabraDisplay4x7(numeros[Minutos / 20], numeros[(((Temp - 600) / 30)) / 2], numeros[0], numeros[0], 1000, 1);
                        }
                        else
                        {
                            display.establecerPalabraDisplay4x7(numeros[Minutos / 20], numeros[(((Temp - 600) / 30)) / 2], numeros[3], numeros[0], 1000, 1);
                        }
                    }
                    else
                    {
                        if (Minutos % 2 == 0)
                        {
                            display.establecerPalabraDisplay4x7(numeros[Minutos / 20], numeros[Minutos / 2], numeros[0], numeros[0], 1000, 1);
                        }
                        else
                        {
                            display.establecerPalabraDisplay4x7(numeros[Minutos / 20], numeros[Minutos / 2], numeros[3], numeros[0], 1000, 1);
                        }
                    }
                }
                else if (boton.leer_boton() == 0)
                {
                    // Enviar señal Lavado
                    cmd = 3;
                    uart_putc(UART_ID, cmd + 0x30);
                    sleep_ms(1000);

                    configuracion = false;
                    trabajar = true;
                }
            }

            bool tiempo_activo = true;
            
            tiempo = 0;
            tiempo = (Temp / 60) * 100;
            tiempo += Temp % 60;

            bool pausa = false;

            while (trabajar == true)
            {
                sleep_ms(500);

                if (boton.leer_boton() == 0)
                {

                    if (pausa == false)
                    {
                        pausa = true;
                        // Envio de señal para pausa
                        cmd = 4;
                        uart_putc(UART_ID, cmd + 0x30);
                        sleep_ms(1000);
                    }
                    else
                    {
                        pausa = false;
                        // Envio de señal de continuación
                        cmd = 3;
                        uart_putc(UART_ID, cmd + 0x30);
                        sleep_ms(1000);
                    }
                    sleep_ms(500);
                }

                while (tiempo_activo)
                {
                    display.establecerPalabraDisplay4x7(0x73, 0x77, 0x3e, 0x6d, 500, 1);
                    sleep_ms(500);
                    if (boton.leer_boton() == 0)
                    {
                        if (pausa == false)
                        {
                            pausa = true;
                            cmd = 4;
                            uart_putc(UART_ID, cmd + 0x30);
                            sleep_ms(1000);
                            // Envio de señal pausa
                        }
                        else
                        {
                            pausa = false;
                            cmd = 3;
                            uart_putc(UART_ID, cmd + 0x30);
                            sleep_ms(1000);
                            // Envio de señal de continuación
                        }
                        sleep_ms(500);
                    }
                    while (tiempo_activo && !pausa)
                    {
                        tiempo_activo = display.establecerCrono4x7(1000, 1, tiempo);
                        if (boton.leer_boton() == 0)
                        {
                            if (pausa == false)
                            {
                                pausa = true;
                                cmd = 4;
                                uart_putc(UART_ID, cmd + 0x30);
                                sleep_ms(1000);
                                // Envio de señal de pausa
                            }
                            else
                            {
                                pausa = false;
                                cmd = 3;
                                uart_putc(UART_ID, cmd + 0x30);
                                sleep_ms(1000);
                                // Envio de señal de continuación
                            }
                            sleep_ms(500);
                        }
                        
                    }
                }
                cmd = 5;
                uart_putc(UART_ID, cmd + 0x30);
                sleep_ms(1000);
                // Envia señal de fin de lavado

                display.establecerPalabraDisplay4x7(0xff, 0xff, 0xff, 0xff, 500, 10);
                trabajar = false;
                botonTemporizador.limpiar_tiempo();
            }
        }
        else
        {
            cmd = 2;
            uart_putc(UART_ID, cmd + 0x30);
            sleep_ms(1000);
            // Enviar señal apagado
            trabajar = false;
            configuracion = true;
            Fase = 0;
            Ciclo = 0;
            Agua = 0;
            Temp = 0;
            Minutos = 0;
            tiempo = 0;
            encendida = true;
            display.establecerPalabraDisplay4x7(0x00, 0x3f, 0x71, 0x71, 1000, 1);
        }
    }
        
}