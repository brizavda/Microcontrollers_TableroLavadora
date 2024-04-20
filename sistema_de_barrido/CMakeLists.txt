cmake_minimum_required(VERSION 3.13)

add_executable(sistema_de_barrido
    sistema_de_barrido.c
)

target_link_libraries(sistema_de_barrido pico_stdlib)


pico_enable_stdio_usb(sistema_de_barrido 1)
pico_enable_stdio_uart(sistema_de_barrido 0)

pico_add_extra_outputs(sistema_de_barrido)
