#define UART_TX_PIN 12
#define UART_RX_PIN 13

#define UART_ID uart0
#define BAUD_RATE 9600
#define BUTTON_ONE_GPIO 15
#define BUTTON_TWO_GPIO 14
#define LED 16

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

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_put(LED, 0);

    while (true)
    {
        // Check if BUTTON_ONE_GPIO is pressed
        if (!gpio_get(BUTTON_ONE_GPIO)) {
            gpio_put(LED, 1);
            cmd_one = (cmd_one % 2) + 1;  // Alternates between 1 and 2
            uart_putc(UART_ID, cmd_one + 0x30); // Convert to ASCII
            sleep_ms(1000);
            gpio_put(LED, 0);
        }
        // Check if BUTTON_TWO_GPIO is pressed
        else if (!gpio_get(BUTTON_TWO_GPIO)) {
            gpio_put(LED, 1);
            cmd_two = (cmd_two % 2) + 3;  // Alternates between 3 and 4
            uart_putc(UART_ID, cmd_two + 0x30); // Convert to ASCII
            sleep_ms(1000);
            gpio_put(LED, 0);
        }
    }
}
