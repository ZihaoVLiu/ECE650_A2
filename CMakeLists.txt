cmake_minimum_required(VERSION 2.8)
project(a2ece650)

## ECE650 Specific configuration start here
## Project specific configurations go here

# enable c++11 support
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

# create the main executable
## add additional .cpp files if needed
add_executable(a2ece650 ece650-a2.cpp )