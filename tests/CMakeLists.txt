find_package(GTest REQUIRED)

# Interface
add_executable(interface
    interface-test.cpp
)

target_link_libraries(interface PRIVATE
    interface_lib
    GTest::Main
)

# Ring Buffer
add_executable(ring_buffer
    ring_buffer-test.cpp
)

target_link_libraries(ring_buffer PRIVATE
    ring_buffer_lib
    GTest::Main
)

# State Machine
add_executable(state_machine
    state_machine-test.cpp
)

target_link_libraries(state_machine PRIVATE
    state_machine_lib
    GTest::Main
)
