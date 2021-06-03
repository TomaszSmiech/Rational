cmake_minimum_required(VERSION 3.10.2)
project(Rational)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE RATIONAL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(Rational_src ${RATIONAL_SRC})
target_include_directories(Rational_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(Rational ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(Rational Rational_src)

file(GLOB_RECURSE RATIONAL_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${RATIONAL_TEST_SRC})


#add_executable(Rational main.cpp Rational.cpp Rational.h)

target_link_libraries(tests Rational_src)
target_link_libraries(tests ${CONAN_LIBS})