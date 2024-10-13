cmake_minimum_required(VERSION 3.1.0)

set(PROJ_NAME cpp)
set(EXE_NAME cpp)
project(${PROJ_NAME} VERSION 1.0)

# CMAKE flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)# 开启后会生成文件compile_commands.json，包含所有编译单元所执行的指令


# Local headers and sources
include_directories(
  "${PROJECT_SOURCE_DIR}/include/")
aux_source_directory("${PROJECT_SOURCE_DIR}/src" SRC_FILES)
set(SRC_LIST main.cpp ${SRC_FILES})

# Generate executable file
add_executable(${EXE_NAME} ${SRC_LIST})

