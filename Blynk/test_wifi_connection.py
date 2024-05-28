import blynkHandler

def main():
    # Inicializar la conexión WiFi y Blynk
    blynk = blynkHandler.init()
    
    # Ejecutar el bucle principal de Blynk
    blynkHandler.run_blynk(blynk)

if __name__ == "__main__":
    main()
