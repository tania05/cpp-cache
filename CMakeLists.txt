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

option(ENABLE_ASAN "Initial Address Sanitizer" false)
if (ENABLE_ASAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

option(ENABLE_UBSAN "Initial Undefined Behaviour Sanitizer" false)
if (ENABLE_UBSAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")
endif()

option(ENABLE_LSAN "Initial Leak Sanitizer" false)
if (ENABLE_LSAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=leak")
endif()

