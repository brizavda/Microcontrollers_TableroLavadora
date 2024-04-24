cmake_minimum_required(VERSION 3.13)

add_executable(boton_nivel_agua
    boton_nivel_agua.c
)

target_link_libraries(boton_nivel_agua pico_stdlib)


pico_enable_stdio_usb(boton_nivel_agua 1)
pico_enable_stdio_uart(boton_nivel_agua 0)

pico_add_extra_outputs(boton_nivel_agua)
