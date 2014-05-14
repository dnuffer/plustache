project(plustache CXX)
cmake_minimum_required(VERSION 2.8)
enable_testing()

include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.53)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_custom_target(check DEPENDS test)
