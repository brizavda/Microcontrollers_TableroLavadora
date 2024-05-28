from machine import ADC 
from time import sleep

sensor_pin = ADC(26)  # Usamos el pin A0 en ESP8266

while True:
    # Lee el valor analógico del sensor
    valor_analogico = sensor_pin.read_u16()
    print(valor_analogico)
    
    if valor_analogico < 500:
        print("Sin agua")
    elif valor_analogico > 500 and valor_analogico < 30000:
        print("Nivel de agua bajo")
    elif valor_analogico > 30001 and valor_analogico < 32000: 
        print("Valor de agua media")
    else: 
        print("Nivel de agua lleno")
    
    sleep(1)  # Espera 1 segundo antes de la siguiente lectura
