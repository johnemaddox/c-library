find_package(GTest REQUIRED)

add_executable(ring_buffer
    ring_buffer-test.cpp
)

target_link_libraries(ring_buffer PRIVATE
    ring_buffer_lib
    GTest::Main
)

# This is here as an example for the next library entry.
add_executable(ring_buffer_2
    ring_buffer-test.cpp
)

target_link_libraries(ring_buffer_2 PRIVATE
    ring_buffer_lib
    GTest::Main
)
