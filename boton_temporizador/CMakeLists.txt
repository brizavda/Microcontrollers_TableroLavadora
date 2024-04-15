cmake_minimum_required(VERSION 3.13)

add_executable(boton_temporizador
    boton_temporizador.c
)

target_link_libraries(boton_temporizador pico_stdlib)


pico_enable_stdio_usb(boton_temporizador 1)
pico_enable_stdio_uart(boton_temporizador 0)

pico_add_extra_outputs(boton_temporizador)
