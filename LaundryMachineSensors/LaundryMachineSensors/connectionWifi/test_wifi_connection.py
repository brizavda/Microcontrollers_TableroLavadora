import time
import network
from machine import Pin, UART
import BlynkLib

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

# Ciclo principal
while True:
    blynk.run()
