from machine import Pin
from time import sleep
from blynk_connection import blynk
from Sensor_temperatura_agua import SensorTemperatura
from Sensor_nivel_agua import SensorNivelAgua

# Inicializa el LED (conectado al pin 15)
led = Pin(15, Pin.OUT)

# Variable para mantener el estado del LED
led_state = False

# Inicializa los sensores
sensor_temperatura = SensorTemperatura(4)  # Reemplaza con el pin correcto
sensor_nivel_agua = SensorNivelAgua(26)    # Reemplaza con el pin correcto

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

# Función para leer los sensores y enviar los datos a Blynk
def read_and_send_sensor_data():
    if led_state:  # Solo lee y envía los datos si el LED está encendido
        try:
            temp_agua = sensor_temperatura.lectura_sensor()
            nivel_agua = sensor_nivel_agua.lectura_valor()

            print('Temperatura del agua: %3.1f C' % temp_agua)
            print('Nivel del agua: %s' % nivel_agua)

            # Envía los datos a Blynk
            blynk.virtual_write(3, temp_agua)  # Virtual pin 3: temperatura del agua
            blynk.virtual_write(4, nivel_agua)  # Virtual pin 4: nivel del agua

        except Exception as e:
            print('Failed to read sensor:', e)

# Bucle principal
while True:
    blynk.run()  # Esto mantiene la conexión con Blynk
    read_and_send_sensor_data()
    sleep(2)  # Espera 2 segundos antes de leer los datos de nuevo
