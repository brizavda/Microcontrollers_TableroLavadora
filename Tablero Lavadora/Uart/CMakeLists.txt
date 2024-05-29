add_executable(uart
    uart.cc
)

target_link_libraries(uart pico_stdlib)
pico_add_extra_outputs(uart)