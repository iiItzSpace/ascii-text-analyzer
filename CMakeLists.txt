cmake_minimum_required(VERSION 4.2)
project(ascii-text-analyzer C)

set(CMAKE_C_STANDARD 23)

add_executable(ascii_text_analyzer
        src/main.c
        include/ascii_stats.h
)

target_include_directories(ascii_text_analyzer PRIVATE include)
