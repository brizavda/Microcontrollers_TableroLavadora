from sensor_temperatura_agua import SensorTemperatura
from time import sleep

Sensor_temperatura = SensorTemperatura(4)

while(True):
    print(Sensor_temperatura.lectura_sensor())
    sleep(1)
