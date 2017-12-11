cmake_minimum_required (VERSION 2.8)

project(hello)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_example0 example0.cpp)

add_executable(cv_example1 example1.cpp)

target_link_libraries(cv_example0 ${OpenCV_LIBS})
target_link_libraries(cv_example1 ${OpenCV_LIBS})
