import time
import melodias

def seleccionar_melodia():
    print("Seleccione una melodía:")
    print("1: Melodía de Inicio")
    print("2: Melodía de Finalización")
    print("3: Melodía de Apagado")
    print("4: Melodía de Pausa")
    print("5: Melodía de Encendido")
    opcion = input("Ingrese el número de la opción deseada: ")

    if opcion == '1':
        print("Reproduciendo Melodía de Inicio...")
        melodias.melodia_inicio()
    elif opcion == '2':
        print("Reproduciendo Melodía de Finalización...")
        melodias.melodia_final()
    elif opcion == '3':
        print("Reproduciendo Melodía de Apagado...")
        melodias.melodia_apagado()
    elif opcion == '4':
        print("Reproduciendo Melodía de Pausa...")
        melodias.melodia_pausa()
    elif opcion == '5':
        print("Reproduciendo Melodía de Encendido...")
        melodias.melodia_encendido()
    else:
        print("Opción no válida. Por favor, intente nuevamente.")

def main():
    while True:
        seleccionar_melodia()
        time.sleep(1)

if __name__ == "__main__":
    main()