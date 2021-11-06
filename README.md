# Vscode + Cmake

```markdown
Linux、Mac下：gcc/g++、gdb、makefile、cmake 等命令在使用之前需要先安装，安装方法请自行搜索。
Windows下：需要安装 MinGW 和 cmake，还要配置环境变量
```

从Vscode中打开项目根目录

1. 在Vscode中安装插件

   * **C/C++** : Micorsoft, C/C++ IntelliSense, debugging, and code browsing
   * **Cmake** : twxs, CMake langage support for Visual Studio Code
   * **Cmake Tools** : Micorsoft, Extended Cmake support in Visual Studio Code

2. 编译工具选择(select kits)    [（参考网站）](https://zhuanlan.zhihu.com/p/52874931) 

   win下Ctrl + Shift + P，(或左下角齿轮 --> 选择Command Palette...)，输入cmake:Select a Kit，选择安装的GCC 8.0.1(即安装的 MinGW 路径下的编译器)

3. 配置(configure)

   等同于执行`cmake ..`，可选择Debug、Release等等，也可以自己自定义配置

4. 编译(build)
   等同于执行`make`，选择编译目标

5. 调试(debug)
   调用gdb进行调试，调试目标选择








### cmake，make流程:

```markdown
CMakeLists.txt -(configure)-> CmakeCache.txt -(generate)-> Makefile
CMakeLists.txt -----------------cmake--------------------- Makefile ----make----> executalbe file
```

### 如何调试(Debug)工程

在CMakeLists.txt中添加Debug参数：

```shell
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
```

若调试工程需要传入参数，在对应工程建立.vscode文件夹settings.json文件里，添加如下：

```shell
{
    // cmake Debug时传给可执行文件的参数，这里为"aaa"和"vvv"
    "cmake.debugConfig": {
        "args": [
            "aaa",
            "vvv"
        ]
    },
}
```

不要添加在系统settings.json(C:\Users\cui\AppData\Roaming\Code\User\settings.json)里，会影响其他工程。

### VsCode 指定默认Generator：

在Windows下，默认的Generator为自带的nmake，同一个项目转移到Linux下时就会比较麻烦。
**方法1：**

```shell
cmake -G "MinGW MakeFiles" ..
```

即每次cmake时都要指定 -G 参数

**方法2：**
在每个CMakeList.txt所在目录建立Preload.cmake文件，以txt形式打开，添加以下内容

```tst
set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
```

（这种方法未在官网给出，[此网页](https://stackoverflow.com/questions/11269833/cmake-selecting-a-generator-within-cmakelists-txt)找到）

**方法3：**
若在CMakeLists.txt中设置`set(CMAKE_GENERATOR "MinGW MakeFiles")`，第一次cmake会使用默认Generator，此时Generator在CMakeCache.txt中被设置，之后就会使用指定的Generator。但此方法要输入两边cmake，有点麻烦    (win下尝试不可用)

cmake 支持 Generator 可参考网站:
https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html



### 参考网站

[1] https://blog.csdn.net/u014265289/article/details/78213643/?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-2

[2] https://zhuanlan.zhihu.com/p/52874931

[3] https://butui.me/post/debug-with-vscode-and-cmake/

[4] https://www.jianshu.com/p/9beafc25f27f
