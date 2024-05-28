import network
import BlynkLib
import time
from machine import UART

# Configuración de la red WiFi
SSID = "INFINITUME7DF_2.4"
PASSWORD = "2ftva4Nazn"
BLYNK_AUTH = "S7taOmoMRuVzJWM7wrT9QSHhDHbx74tb"

# Inicialización de UART (usamos UART0: TX=GP16, RX=GP17)
uart = UART(0, baudrate=9600, tx=16, rx=17)

# Conexión a la red WiFi
def connect_wifi(ssid, password):
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)

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

# Inicialización de Blynk
def init_blynk(blynk_auth):
    blynk = BlynkLib.Blynk(blynk_auth)

    @blynk.on("V1")
    def v1_write_handler(value):
        if int(value[0]) == 1:
            uart.write('ON\n')
        else:
            uart.write('OFF\n')

    return blynk

def run_blynk(blynk):
    while True:
        blynk.run()

# Inicialización de WiFi y Blynk
def init():
    connect_wifi(SSID, PASSWORD)
    blynk = init_blynk(BLYNK_AUTH)
    return blynk
