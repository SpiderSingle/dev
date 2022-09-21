cmake_minimum_required(VERSION 2.8)
PROJECT(TEST)


set(vector_src cvector/cvector.h cvector/cvector.cpp cvector/main.cpp )

set(cstring_src cstring/cstring.h cstring/cstring.cpp cstring/main.cpp )

set(smartpointer_src smartpointer/main.cpp )


add_executable(cvector ${vector_src})
add_executable(cstring ${cstring_src})
add_executable(smartpointer ${smartpointer_src})


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../../bin)







