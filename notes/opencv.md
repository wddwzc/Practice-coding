ros安装目录： /opt/ros

opencv包含其中，kinetic自带3.3.1版本opencv

FIND_PACKAGE( OpenCV REQUIRED )时

系统默认在/usr/share/OpenCV下找OpenCVConfig.cmake，确定引入的Opencv的头文件和库文件的位置。

当使用其他版本的OpenCV时：

FIND_PACKAGE( OpenCV REQUIRED ) 前，添加

set(OpenCV_DIR "usr/local/opencv3/share/OpenCV")

## OpenCV安装
### 源码编译安装

pkg-config --modversion opencv  查看opencv版本

但该方式不适用于ros自带opencv

安装

默认的安装路径是/usr/local/bin、/usr/local/include

自定义安装如下：

```
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local/opencv2411 ..
make    # 自定义的安装路径
sudo make install
```

在bashrc文件中来设置PKG_CONFIG_PATH
```
sudo gedit ~/.bashrc
export PKG_CONFIG_PATH=/usr/local/opencv2411/lib/pkgconfig
export LD_LIBRARY_PATH=/usr/local/opencv2411/lib
```

CMakeLists.txt中需要的修改：

```
set(OpenCV_DIR /usr/local/opencv2411/share/OpenCV)
find_package(OpenCV 2.4 REQUIRED)
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS} /usr/local/opencv2411/include)

find_package(OpenCV REQUIRED)
```

库文件默位置/usr/local/lib/python2.7/site-packages

cv2.so和cv.py

将编译好的python依赖库cv2.so拷贝到对应的site-packages文件夹中即可

### Anaconda安装

conda install --channel https://conda.anaconda.org/menpo opencv3

### pip安装

仅安装opencv-python

pip install opencv-python

或在https://www.lfd.uci.edu/~gohlke/pythonlibs/#opencv下载对应版本

pip install filename

## 导入问题

import时，会在系统变量 PYTHONPATH 中检索，然后才是anaconda的包安装目录（大概）

如果在.bashrc中配置了ROS路径，PYTHONPATH的值为/opt/ros/kinetic/lib/python2.7/dist-packages

导致使用conda中的环境时，导入cv2出错
