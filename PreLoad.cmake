# 此文件的存在是为了避免每次cmake时都要指定 -G 参数，即每次都输入
# cmake -G "MinGW MakeFiles" .. ，但二者效果一样


# 在每个CMakeList.txt所在目录建立Preload.cmake文件，添加以下内容
# （这种方法未在官网给出，从网页找到）
set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)

# 若在CMakeLists.txt中设置set(CMAKE_GENERATOR "MinGW Makefiles")，第一次cmake
# 会使用默认Generator，此时Generator在CMakeCache.txt中被设置，之后就会
# 使用指定的Generator。但此方法要输入两边cmake，有点麻烦(win下尝试不可用)

# cmake 支持 Generator 可参考网站:
# https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html

# cmake, make流程:
# CMakeLists.txt -(configure)-> CmakeCache.txt -(generate)-> Makefile
# CMakeLists.txt -----------------cmake--------------------- Makefile ----make----> executalbe file