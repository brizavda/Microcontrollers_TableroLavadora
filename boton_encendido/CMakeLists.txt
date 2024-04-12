cmake_minimum_required(VERSION 3.13)

add_executable(boton_encendido
    boton_encendido.c
)

target_link_libraries(boton_encendido pico_stdlib)


pico_enable_stdio_usb(boton_encendido 1)
pico_enable_stdio_uart(boton_encendido 0)

pico_add_extra_outputs(boton_encendido)

