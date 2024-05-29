#define UART_TX_PIN 16
#define UART_RX_PIN 17

#define UART_ID uart0
#define BAUD_RATE 9600
#define BUTTON_ONE_GPIO 22
#define BUTTON_TWO_GPIO 20

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"

int main()
{
    uint8_t cmd_one = 0;
    uint8_t cmd_two = 0;

    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    gpio_init(BUTTON_ONE_GPIO);
    gpio_set_dir(BUTTON_ONE_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_ONE_GPIO);

    gpio_init(BUTTON_TWO_GPIO);
    gpio_set_dir(BUTTON_TWO_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_TWO_GPIO);


    while (true)
    {
        // Check if BUTTON_ONE_GPIO is pressed
        if (!gpio_get(BUTTON_ONE_GPIO)) {
            cmd_one = 7;  // Alternates between 1 and 2
            uart_putc(UART_ID, cmd_one + 0x30); // Convert to ASCII
            sleep_ms(1000);
        }
        // Check if BUTTON_TWO_GPIO is pressed
        else if (!gpio_get(BUTTON_TWO_GPIO)) {
            cmd_two = 2;  // Alternates between 3 and 4
            uart_putc(UART_ID, cmd_two + 0x30); // Convert to ASCII
            sleep_ms(1000);
        }
    }
}