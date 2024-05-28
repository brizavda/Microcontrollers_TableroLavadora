from Sensor_temperatura_agua import SensorTemperatura
from Sensor_nivel_agua import SensorNivelAgua 
from sensor_Ultrasonic import init_ultrasonic, measure_distance
import melodias
import BlynkLib
from machine import Pin, PWM
from time import sleep_ms
import network
from machine import Pin, UART
from machine import I2C
from ssd1306 import SSD1306_I2C


def main():
    # Configuración del zumbador en el pin GP14
    zumbador = PWM(Pin(13))
    Sensor_temperatura_agua = SensorTemperatura(4)
    Sensor_nivel_agua = SensorNivelAgua(26)
    # Initialize GPIOs
    trigger_pin = 15
    echo_pin = 14
    trigger, echo = init_ultrasonic(trigger_pin, echo_pin)
    
    Pin_SDA = 18
    Pin_SCL = 19
    
    uart = UART(0, baudrate=9600, tx=Pin(16), rx=Pin(17))
    

    pinesI2c = I2C(sda = Pin(Pin_SDA), scl = Pin(Pin_SCL), id = 1)

    display = SSD1306_I2C(128, 64, pinesI2c)
    
    """
    # Configuración de la red WiFi
    SSID = "INFINITUME7DF_2.4" # Nombre de tu WiFi
    PASSWORD = "2ftva4Nazn" # Contraseña de tu WiFi
    BLYNK_AUTH = "S7taOmoMRuVzJWM7wrT9QSHhDHbx74tb" # Token de Blynk

    # Conexión a la red WiFi
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)

    # Espera a que se establezca la conexión
    max_wait = 10
    while max_wait > 0:
        if wlan.isconnected():
            break
        print('Esperando conexión...')
        time.sleep(1)
        max_wait -= 1

    if not wlan.isconnected():
        raise RuntimeError('Falló la conexión a la red')
    else:
        print('Conectado')
        ip = wlan.ifconfig()[0]
        print('IP:', ip)

    # Conexión a Blynk
    blynk = BlynkLib.Blynk(BLYNK_AUTH)

    # Configuración UART
    uart = UART(0, baudrate=9600, tx=16, rx=17)

    # Manejador para el pin virtual V1
    def v1_write_handler(value):
        if int(value[0]) == 1:
            uart.write('ON\n')
        else:
            uart.write('OFF\n')
    """
            
    cmd_value = 1
    while(True):
        
        if uart.any():
            cmd = uart.read(1)
            cmd_value = int(cmd)
            print(cmd_value)
            
        if cmd_value == 1:  
                
            temp = Sensor_temperatura_agua.lectura_sensor()
            niv_ag = Sensor_nivel_agua.lectura_valor()
            dist = measure_distance(trigger, echo)
            temperatura = f"Temp: : {temp}"
            nivel_agua = f"{niv_ag}"
            distancia = f"Volu ropa: {dist}"
            display.fill(0)
            display.text(temperatura, 0, 0)
            display.text(nivel_agua, 0, 10)
            display.text(distancia, 0, 20)
            display.show()
            sleep_ms(50)
            
        elif cmd_value == 2: 
            display.fill(0)
            display.text("Pausa", 0, 0)
            display.show()
            sleep_ms(1000)
            
        elif cmd_value == 3: 
            display.fill(0)
            display.text("Configuracion", 0, 0)
            display.show()
            sleep_ms(1000)
            
if __name__ == "__main__":
    main()