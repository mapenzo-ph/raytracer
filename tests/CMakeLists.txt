# enable tests
enable_testing()

add_executable(test_color test_color.cpp)
target_link_libraries(test_color PRIVATE libraytracer)
add_test(NAME Color COMMAND test_color)