from machine import ADC 
from time import sleep

sensor_pin = ADC(26)  # Usamos el pin A0 en ESP8266

while True:
    # Lee el valor analógico del sensor
    valor_analogico = sensor_pin.read_u16()
    print(valor_analogico)
    
    
    
    sleep(1)  # Espera 1 segundo antes de la siguiente lectura
