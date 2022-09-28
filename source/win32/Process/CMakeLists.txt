cmake_minimum_required(VERSION 2.8)


set(ONEXIT_SRC ${CMAKE_CURRENT_LIST_DIR}/OnExit.cpp)




set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../../bin)

add_executable(OnExit ${ONEXIT_SRC})


