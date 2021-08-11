set(exec_name ${CMAKE_PROJECT_NAME}_test)

set(src_list
    main.cpp
    ring_buffer-test.cpp
)

add_executable(${exec_name} ${src_list})

add_test(NAME ${exec_name} COMMAND ${exec_name})

target_link_libraries(${exec_name} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest pthread)
