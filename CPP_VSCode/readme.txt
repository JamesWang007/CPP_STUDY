# important commands
cmake_minimum_required(VERSION 2.8.3)

# assign the project name as HELLOWORLD
project(HELLOWORLD)

# 定义SRC变量，其值为sayhello.cpp hello.cpp
set(SRC sayhello.cpp hello.cpp)


# add /usr/include/myincludefolder and ./include to path of head files
# equvilent to -I
include_directories(/usr/include/myincludefolder ./include)


# add 
# -l : search directory
link_directories(/usr/mylibfolder ./lib)


# add library - create a library 
# [SHARED][STATIC]
add_library(hello SHARED ${SRC})


# add compile premeters: 
# -wall -std=c++11 -o2
add_compile_options(-wall -std=c++11 -o2)


# create exectuable file
add_executable(main main.cpp)


# add dynamic library to target
target_link_libraries(main hello)


# add src sub directory
# need a CMakeLists.txt in the sub directory
add_subdirectory(src)


# define a SRC variable, value of which will be 
# the source code of all the files in current directory
aux_source_directory(. SRC)
# compile the source code and create an exectuable file --main 
add_executable(main ${SRC})



# CMAKE_C_FLAGS
# CMAKE_CXX_FLAGS
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )



# CMAKE_BUILD_TYPE
set( CMAKE_BUILD_TYPE Debug)
set( CMAKE_BUILD_TYPE Release)