cmake_minimum_required (VERSION 2.6)
project (ReportGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(src)
add_subdirectory(test)
