from machine import Pin, UART, I2C
from utime import sleep

def main() -> None:
    uart = UART(0, baudrate=9600, tx=Pin(12), rx=Pin(13))

    while True:
        if uart.any():
            cmd = uart.read(1)
            try:
                cmd_val = int(cmd)
            except ValueError:
                print(cmd)
            except:
                print("error")
            else:
                print(cmd_val)
                if cmd_val == 1:
                    print(cmd)
                elif cmd_val == 2:
                    print(cmd)
                elif cmd_val == 3:
                    print(cmd)
                elif cmd_val == 4:
                    print(cmd)
                else:
                   print(cmd)
            finally:
                print("Conexion")
            

if __name__ == '__main__':
    main()