cmake_minimum_required(VERSION 3.12)

#5. add executable
add_executable(boton_PlayPause
    #boton_PlayPause.cc
    main.cc
)

#7. add target libraries 
target_link_libraries(boton_PlayPause 
    pico_stdlib
    pico_cyw43_arch_none
)

# enable usb output, disable uart output
pico_enable_stdio_usb(boton_PlayPause 1)
pico_enable_stdio_uart(boton_PlayPause 0)

# Build uf2 file
pico_add_extra_outputs(boton_PlayPause)