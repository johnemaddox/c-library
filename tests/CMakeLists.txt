find_package(GTest REQUIRED)

add_executable(${OUTPUT}
    ${MY_PROG}-test.cpp
)

target_link_libraries(${OUTPUT} PRIVATE
    ${MY_PROG}_lib
    GTest::Main
)
