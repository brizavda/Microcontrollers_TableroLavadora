cmake_minimum_required(VERSION 3.12)

#5. add executable
add_executable(boton_TipoCiclos
    boton_TipoCiclos.cc
    main.cc
)

#7. add target libraries 
target_link_libraries(boton_TipoCiclos 
    pico_stdlib
)

# enable usb output, disable uart output
pico_enable_stdio_usb(boton_TipoCiclos 1)
pico_enable_stdio_uart(boton_TipoCiclos 0)

# Build uf2 file
pico_add_extra_outputs(boton_TipoCiclos)