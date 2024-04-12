cmake_minimum_required(VERSION 3.13)

add_executable(boton_inicio
    boton_inicio.c
)

target_link_libraries(boton_inicio pico_stdlib)


pico_enable_stdio_usb(boton_inicio 1)
pico_enable_stdio_uart(boton_inicio 0)

pico_add_extra_outputs(boton_inicio)