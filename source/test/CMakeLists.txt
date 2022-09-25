cmake_minimum_required(VERSION 2.8)
PROJECT(TEST)

#设置源文件的路径变量
set(vector_src cvector/cvector.h cvector/cvector.cpp cvector/main.cpp )

set(cstring_src cstring/cstring.h cstring/cstring.cpp cstring/main.cpp )

set(sstream sstream/sstream.cpp)

set(smartpointer_src smartpointer/main.cpp )

#设置程序的输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../../bin)

#生成可执行的文件
add_executable(cvector ${vector_src})
add_executable(cstring ${cstring_src})
add_executable(smartpointer ${smartpointer_src})
add_executable(sstream ${sstream})

#设置文件夹分组
set_property(TARGET  cvector PROPERTY FOLDER  "test")
set_property(TARGET  cstring PROPERTY FOLDER "test")
set_property(TARGET  smartpointer PROPERTY FOLDER "test")
set_property(TARGET  sstream PROPERTY  FOLDER "test")





