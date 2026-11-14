cmake_minimum_required(VERSION 4.2)
project(ascii-text-analyzer C)

set(CMAKE_C_STANDARD 23)

add_executable(ascii_text_analyzer
        src/main.c
        src/input_reader.c
        include/ascii_stats.h
)

target_include_directories(ascii_text_analyzer PRIVATE include)

enable_testing()

add_executable(test_input_reader
    tests/test_input_reader.c
        src/input_reader.c
)
target_include_directories(test_input_reader PRIVATE include)
add_test(NAME test_input_reader COMMAND test_input_reader)