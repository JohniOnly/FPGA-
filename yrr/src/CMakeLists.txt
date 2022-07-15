cmake_minimum_required(VERSION 2.8)
aux_source_directory(. DIR_WORLD_SRCS)
# include_directories(../include) //main CMakeLists include
# set(CMAKE_Cxx_FLAGS "${CMAKE_Cxx_FLAGS} -g -Wall")
add_library(rela_l ${DIR_WORLD_SRCS})