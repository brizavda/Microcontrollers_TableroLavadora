from Sensor_temperatura_agua import SensorTemperatura
from Sensor_nivel_agua import SensorNivelAgua 
from sensor_Ultrasonic import init_ultrasonic, measure_distance
import melodias
from blynk_connection import blynk
from machine import Pin, PWM
from time import sleep_ms
import network
from machine import Pin, UART
from machine import I2C
from ssd1306 import SSD1306_I2C


def main():
     # Configuración del zumbador en el pin GP1
    Sensor_temperatura_agua = SensorTemperatura(4)
    Sensor_nivel_agua = SensorNivelAgua(26)
    # # Initialize GPIOs
    trigger_pin = 15
    echo_pin = 14
    trigger, echo = init_ultrasonic(trigger_pin, echo_pin)
    
    uart = UART(0, baudrate=9600, tx=Pin(16), rx=Pin(17))
    i2c = I2C(1, sda=Pin(18), scl=Pin(19), freq=400000)
    display = SSD1306_I2C(128, 64, i2c)
    
    musica_inicio = True
    cmd_value = 2
    
    while True:
        
        
        if uart.any():
            cmd = uart.read(1)
            try:
                cmd_value = int(cmd)
            except ValueError:
                print(cmd)
                display.text(f'Error: cmd', 0, 10)
                display.text('is not numeric', 0, 20)
            except:
                display.text('Error: cmd unknown', 0, 10)
          
          
        if cmd_value == 1:
            display.fill(0)
            display.text("Encendida ", 0, 0)
            display.show()
            melodias.melodia_encendido()
            sleep_ms(1000)
            
            
            cmd_value = 6
        elif cmd_value == 2:
            # Apagar
            display.fill(0)
            display.text("Apagada", 0, 0)
            display.show()
            melodias.melodia_apagado()
            sleep_ms(1000)
            
            
            
        elif cmd_value == 6:  
            display.fill(0)
            display.text("Configuracion", 0, 0)
            display.show()
            sleep_ms(1000)
            
        elif cmd_value == 4: 
            musica_inicio = True
            display.fill(0)
            display.text("Pausa", 0, 0)
            display.show()
            melodias.melodia_pausa()
            sleep_ms(1000)
            
        elif cmd_value == 3:
            
            if musica_inicio == True: 
                melodias.melodia_inicio()
                musica_inicio = False
                
            
            
            temp = Sensor_temperatura_agua.lectura_sensor()
            agua = Sensor_nivel_agua.valor_analogico()
            niv_ag = Sensor_nivel_agua.lectura_valor()
            dist = measure_distance(trigger, echo)
            temperatura = f"Temp: : {temp}"
            nivel_agua = f"{niv_ag}"
            distancia = f"{dist}"
            display.fill(0)
            display.text(temperatura, 0, 0)
            display.text(nivel_agua, 0, 10)
            display.text(distancia, 0, 20)
            display.show()
            blynk.run()
            blynk.virtual_write(5, temp)
            blynk.virtual_write(6, agua)
            sleep_ms(1000)
        
        elif cmd_value == 5:
            display.fill(0)
            display.text("Finalizacion", 0, 0)
            display.show()
            melodias.melodia_final()
            sleep_ms(1000)
            cmd_value = 6
        else:
            display.fill(0)
            display.text("Error", 0, 0)
            print("Error")
            display.show()
            sleep_ms(1000)
           
            
        
            

    

            
            
    
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
            
    
    
    
    
    while(False):
        
        if uart.any():
            cmd = uart.read(1)
            cmd_value = int(cmd)
            print(cmd_value)
           
            
        if cmd_value == 1:
            display.fill(0)
            display.text("Encendida ", 0, 0)
            display.show()
            melodias.melodia_encendido()
            sleep_ms(1000)
            
            
            cmd_value = 6
        elif cmd_value == 2:
            # Apagar
            display.fill(0)
            display.text("Apagada", 0, 0)
            display.show()
            melodias.melodia_apagado()
            sleep_ms(1000)
            
            
            
        elif cmd_value == 6:  
            display.fill(0)
            display.text("Configuracion", 0, 0)
            display.show()
            sleep_ms(1000)
            
        elif cmd_value == 4: 
            display.fill(0)
            display.text("Pausa", 0, 0)
            display.show()
            melodias.melodia_pausa()
            sleep_ms(1000)
            
        elif cmd_value == 3:
            
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
        
        elif cmd_value == 5:
            display.fill(0)
            display.text("Finalizacion", 0, 0)
            display.show()
            melodias.melodia_final()
            sleep_ms(1000)
            cmd_value = 6
        else:
            display.fill(0)
            display.text("Error", 0, 0)
            print("Error")
            display.show()
            sleep_ms(1000)
            
            
            
            
            
            
            
if __name__ == "__main__":
    main()