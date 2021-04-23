# cmake . -G "MinGW Makefiles"
#
#

cmake_minimum_required(VERSION 3.0)


project(HELLOWORLD)


include_directories(include)


# add_executable(helloWorld_cmake helloworld.cpp)
aux_source_directory(./src SRC)
add_executable(main_cmake main.cpp ${SRC})



