相关环境变量：
* LD_LIBRARY_PATH：库文件路径
* PKG_CONFIG_PATH：库配置文件路径

一般 LD_LIBRARY_PATH=PKG_CONFIG_PATH/pkgconfig

库安装完成后会有一个目录为pkgconfig，其中有文件叫*.pc

把这个目录放到PKG_CONFIG_PATH中，其他库软件安装才会使用到这个库

### configure、pkg-config、pkg_config_path
* configure

configure程序它会根据传入的配置项目检查程序编译时所依赖的环境以及对程序编译安装进行配置，最终生成编译所需的Makefile文件供程序Make读入使用进而调用相关编译程式(通常调用编译程序都是gcc)来编译最终的二进制程序。而configure脚本在检查相应依赖环境时(例：所依赖软件的版本、相应库版本等)，通常会通过pkg-config的工具来检测相应依赖环境。

* pkg-config

pkg-config用来检索系统中安装库文件的信息。典型的是用作库的编译和连接。

环境变量PKG_CONFIG_PATH是用来设置.pc文件的搜索路径。

这样，库的头文件的搜索路径的设置实际上就变成了对.pc文件搜索路径的设置。

设置环境变量：
```
$ export PKG_CONFIG_PATH=/opt/gtk/lib/pkgconfig:$PKG_CONFIG_PATH
```

### OpenCV安装
