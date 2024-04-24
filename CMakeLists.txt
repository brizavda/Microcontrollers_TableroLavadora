cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
project(Microcontrollers_TableroLavadora C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

pico_sdk_init()
add_subdirectory(boton_encendido)
add_subdirectory(boton_nivel_agua)
add_subdirectory(sistema_de_barrido)
add_subdirectory(modu_boton_encendido)






