cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

set(exe_name ${PROJECT_NAME})

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(corelib OBJECT ConfigParser.cpp NewWAV.cpp Processor.cpp WAVparser.cpp)

add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)