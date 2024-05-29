cmake_minimum_required(VERSION 3.13)

add_executable(boton_InicioPausa
    test.cc
)

target_link_libraries(boton_InicioPausa pico_stdlib)


pico_enable_stdio_usb(boton_InicioPausa 1)
pico_enable_stdio_uart(boton_InicioPausa 0)

pico_add_extra_outputs(boton_InicioPausa)