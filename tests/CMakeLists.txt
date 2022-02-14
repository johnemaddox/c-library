find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(tests
    ring_buffer-test.cpp
)

target_link_libraries(tests PRIVATE
    ring_buffer_lib
    GTest::Main
)

gtest_discover_tests(tests)
