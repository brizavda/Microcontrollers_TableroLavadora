from Sensor_nivel_agua import SensorNivelAgua
from time import sleep

sensor_nivel_agua = SensorNivelAgua(26)

while(True):
    print(sensor_nivel_agua.lectura_valor())
    sleep(1)

    