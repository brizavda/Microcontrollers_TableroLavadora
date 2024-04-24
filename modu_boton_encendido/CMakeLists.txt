cmake_minimum_required(VERSION 3.13)

add_executable(modu_boton_encendido
    modu_boton_encendido.cc
    test.cc
)

target_link_libraries(modu_boton_encendido pico_stdlib)


pico_enable_stdio_usb(modu_boton_encendido 1)
pico_enable_stdio_uart(modu_boton_encendido 0)

pico_add_extra_outputs(modu_boton_encendido)