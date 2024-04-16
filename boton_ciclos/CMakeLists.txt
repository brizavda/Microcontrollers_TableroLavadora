cmake_minimum_required(VERSION 3.13)

add_executable(boton_ciclos
    boton_ciclos.c
)

target_link_libraries(boton_ciclos pico_stdlib)


pico_enable_stdio_usb(boton_ciclos 1)
pico_enable_stdio_uart(boton_ciclos 0)

pico_add_extra_outputs(boton_ciclos)
