cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)



project(pico-fibonacci C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

#4. initialize the pico sdk 
pico_sdk_init()

add_subdirectory(Fibonacci)
add_subdirectory(hello_7segment)
