cmake_minimum_required(VERSION  2.8)
project(ocean-data CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# find_package(Boost COMPONENTS filesystem system iostreams REQUIRED)
find_package(Matplot++ REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# file(GLOB SRCS src/*.cpp)
add_executable(ocean-data plot.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Matplot++::matplot)