set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cpp_containers LANGUAGES CXX)


add_executable(test_matrix_transpose app/test_matrix_transpose.cpp include/ra/matrix_transpose.hpp)
add_executable(test_matrix_multiply app/test_matrix_multiply.cpp include/ra/matrix_multiply.hpp)
add_executable(test_fft app/test_fft.cpp include/ra/fft.hpp)

target_include_directories(test_matrix_transpose PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")
target_include_directories(test_matrix_multiply PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")
target_include_directories(test_fft PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")




