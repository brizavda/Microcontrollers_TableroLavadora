from machine import Pin
from time import sleep
import dht
from blynk_connection import blynk

# Inicializa el sensor DHT11
sensor = dht.DHT11(Pin(22))

# Inicializa el LED (conectado al pin 15)
led = Pin(15, Pin.OUT)

# Variable para mantener el estado del LED
led_state = False

# Callback para el control del LED desde Blynk
def control_led(value):
    global led_state
    if int(value[0]) == 1:
        led.value(1)  # Enciende el LED
        led_state = True
    else:
        led.value(0)  # Apaga el LED
        led_state = False

# Registra el callback para el pin virtual 1
blynk.on("V1", control_led)

# Función para leer el sensor y enviar los datos a Blynk
def read_and_send_sensor_data():
    if led_state:  # Solo lee y envía los datos si el LED está encendido
        try:
            sensor.measure()
            temp = sensor.temperature()
            hum = sensor.humidity()

            print('Temperature: %3.1f C' % temp)
            print('Humidity: %3.1f %%' % hum)

            # Envía los datos a Blynk
            blynk.virtual_write(3, temp)  # Virtual pin 3: temperatura en Celsius
            blynk.virtual_write(4, hum)  # Virtual pin 4: humedad

        except OSError as e:
            print('Failed to read sensor.')

# Bucle principal
while True:
    blynk.run()  # Esto mantiene la conexión con Blynk
    read_and_send_sensor_data()
    sleep(2)  # Espera 2 segundos antes de leer los datos de nuevo
