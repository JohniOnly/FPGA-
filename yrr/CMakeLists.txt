cmake_minimum_required(VERSION 2.8)
project(Scaler)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)
aux_source_directory(./src SUBSRC)
# Add header file include directories
# include_directories(./ ./src)
include_directories(include)
# Add block directories
add_subdirectory(src)

LINK_LIBRARIES(m)


set(CMAKE_Cxx_FLAGS "${CMAKE_Cxx_FLAGS} -g -Wall")

set(CMAKE_BUILD_TYPE Debug)
# Target
add_executable(Scaler ${DIRSRCS} ${SUBSRC})

target_link_libraries(Scaler rela_l m) 

