import machine
import time

# Configura el pin donde está conectado el sensor de nivel de agua DGZZI
sensor_pin = machine.Pin(15, machine.Pin.IN)  # Usamos el pin D6 en ESP8266

while True:
    # Lee el estado del sensor
    nivel_agua = sensor_pin.value()
    time.sleep(1)
    
    print(nivel_agua)
