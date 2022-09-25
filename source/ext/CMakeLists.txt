cmake_minimum_required(VERSION 2.8)
project(ext)


set(INI_SRC IniFile/CIniFile.cpp IniFile/CIniFile.h)
set(INI_TEST_SRC IniTest/main.cpp)


add_executable(IniFile ${INI_SRC} ${INI_TEST_SRC}) 

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../../bin)

set_property(TARGET  IniFile PROPERTY FOLDER  "ext")




