cmake_minimum_required(VERSION 2.8)
project(dev)
SUBDIRS(test ext) 


IF(MSVC)
    SUBDIRS(win32)
ENDIF(MSVC)

#设置文件夹选项
set_property(GLOBAL PROPERTY USE_FOLDERS ON)






