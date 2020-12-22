# 深度学习环境

## I Graphic Driver

### 1 依赖库

```
sudo apt-get install libcupti-dev
```

### 2 卸载nvidia驱动

安装驱动前需要卸载老版本

* 驱动和系统或硬件不兼容：导致输入登录密码后，桌面一闪而过，回到登陆界面
* 老版本导致新驱动安装失败

卸载与安装时需要进行显示模式的切换：

* ctrl+alt+F1进入终端模式
* ctrl+alt+F7进入图形桌面模式

或

* init 3  进入终端模式
* init 5  进入图形模式

在终端模式下开始卸载驱动
```
### 通过apt-get方式安装的
sudo apt-get remove --purge nvidia-*   # 可添加前面安装的版本号
# 由于ubuntu-desktop的依赖项是nvidia，所以重新安装
sudo apt-get install ubuntu-desktop
### 通过runfile安装的
sudo chmod +x *.run
sudo ./NVIDIA-Linux-x86_64-384.59.run --uninstall
# 或如下
sudo sh ./NVIDIA-Linux-x86_64-367.44.run --uninstall
# 或
sudo /usr/bin/nvidia-uninstall

# 重启
sudo reboot
```
错误日志文件是~/.xsession-errors

### 3 禁用nouveau

nouveau驱动是ubuntu自带的开源nvidia驱动，没有GPU加速功能

nouveau，是一个自由及开放源代码显卡驱动程序，是为Nvidia的显示卡所编写，也可用于属于系统芯片的NVIDIA Tegra系列，此驱动程序是由一群独立的软件工程师所编写，Nvidia的员工也提供了少许帮助。该项目的目标为利用逆向工程Nvidia的专有Linux驱动程序来创造一个开放源代码的驱动程序。所以nouveau开源驱动基本上是不能正常使用的，性能极低。
```
# 在黑名单blacklist.conf中添加条目
sudo gedit /etc/modprobe.d/blacklist-nouveau.conf
```
添加如下内容
```
# 经尝试，前两条即可
blacklist nouveau
options nouveau modeset=0
blacklist lbm-nouveau
alias nouveau off
alias lbm-nouveau off
```
在终端中执行
```
# 该条语句待考证作用
echo options nouveau modeset=0 | sudo tee -a /etc/modprobe.d/nouveau-kms.conf
sudo update-initramfs -u
sudo reboot
```
重启后，检测nouveau是否已禁止，如下指令会输出nouveau的设备和运行信息
```
# 如果没有输出，则屏蔽成功
lsmod | grep nouveau
```

### 4 安装nvidia驱动

#### 4.1 apt-get安装

该方式安装的是ubuntu的专有nvidia驱动，但该驱动一般不是最新的或是所需的

**查看ubuntu专有驱动**

```
sudo ubuntu-drivers devices
```
```
# 查看N卡型号
sudo lspci | grep -i nvidia
```

**安装专有驱动**

该专有驱动是apt-get可以获取的驱动，其它版本无法获取
```
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt-get update
sudo apt-get install nvidia-390   # 这边数字对应上面搜索出的版本
sudo apt-get install mesa-common-dev
sudo apt-get install freeglut3-dev
# 完成后重启
reboot
```

**查看是否安装成功**

在About this computer中查看显卡栏，或如下方式：
```
# 输出nvidia硬件及驱动信息
nvidia-smi
# 打开nvidia控制面板
nvidia-settings
```

#### 4.2 runfile安装

在官网下载[GPU驱动](https://developer.nvidia.com/)

**关闭UEFI模式**

安装驱动的需要，关闭Secure Boot，就可以切换到Legacy模式

**关闭X server服务**

需要在命令行界面安装（ctrl+alt+F1/F2/F7切换），关闭x-server（阻碍驱动安装）
在ubuntu18中装的时候，没有lightdm
```
# 结束/开启x-window的服务
sudo service lightdm stop
# 安装完成后开启
sudo service lightdm start
```

**run安装**

```
# 最好参照按照官网的提示来
sudo chmod +x NVIDIA-Linux-x86_64-375.20.run
sudo ./NVIDIA-Linux-x86_64-375.20.run -no-x-check -no-nouveau-check -no-opengl-files
```
这三个参数时用来防止循环登录，如果提示无法安装32-bit lib，没有影响

* -no-opengl-files 只安装驱动文件，不安装OpenGl文件（**该项必选**，因为ubuntu本身有OpenGL，且与GUI息息相关，nvidia驱动覆写了OpenGL会导致链接库出问题。没有该选项也可能导致安装失败）
* -no-x-check 不见差x服务
* -no-nouveau-check 安装时不检查nouveau，但可能因为nouveau未禁用而安装失败

安装过程：

```
The distribution-provided pre-install script failed!  Are you sure you want
  to continue?                                                                 
       
                 Continue installation      Abort installation       

----> Continue installation

Would you like to register the kernel module sources with DKMS? This will    
  allow DKMS to automatically build a new module, if you install a different   
  kernel later.

                          Yes                       No  
---->No

 The CC version check failed:

  The kernel was built with gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1), 
  but the current compiler version is cc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0.  

  This may lead to subtle problems; if you are not certain whether the         
  mismatched compiler will be compatible with your kernel, you may wish to     
  abort installation, set the CC environment variable to the name of the       
  compiler used to compile your kernel, and restart installation.

                Ignore CC version check     Abort installation         

----> select ignore

 WARNING: Ignoring CC version mismatch:

           The kernel was built with gcc version 7.4.0 (Ubuntu
           7.4.0-1ubuntu1~18.04.1), but the current compiler version is cc     
           (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0.

                                       OK  
----> OK

Install NVIDIA's 32-bit compatibility libraries?
                                                                               
                          Yes                       No   
----> No

 An incomplete installation of libglvnd was found. All of the essential       
  libglvnd libraries are present, but one or more optional components are      
  missing. Do you want to install a full copy of libglvnd? This will overwrite 
  any existing libglvnd libraries.

      Don't install  Install and overw          Abort installation.       

---->Install and overw

Would you like to run the nvidia-xconfig utility to automatically update
  your X configuration file so that the NVIDIA X driver will be used when you
  restart X?  Any pre-existing X configuration file will be backed up.         
                                                                      
                          Yes                       No                 
                          
---->Yes

Your X configuration file has been successfully updated.  Installation of    
  the NVIDIA Accelerated Graphics Driver for Linux-x86_64 (version: 440.100)   
  is now complete.

                                       OK  
----> OK

```

#### 4.3 使用标准仓库进行自动化安装

在安装的发行版中，如 ubuntu, Linux Mint等，找到**附加驱动管理软件**，直接安装

这种安装方式有如下缺点：

* 如果你的显卡比较新可能会出现安装低版本的NVIDIA驱动而造成即可安装完成，但是并没有真正安装成功，可能会出现循环登录，关机死机等等原因。
* 当你更换驱动的时候可能原有的NVIDIA驱动删除不干净。

当然这种方式也是有优点的:

* 不需要手动禁止nouveau
* 操作方便

可能有的童鞋还使用过命令行的方式安装：
```
sudo apt-get install nvidia*
```
这种方式安装同样也是使用ubuntu官方源的形式安装的，你可以选择不同的驱动版本来安装，但是本质上和标准仓库进行自动化安装是一样的。

ubuntu自带命令行版本安装工具ubuntu-drivers,终端输入:
```
ubuntu-drivers devices   # 查询所有ubuntu推荐的驱动
sudo ubuntu-drivers autoinstall     # 安装所推荐的驱动版本
```

### 5 独显 & 核显切换

1. 检查显卡
```
lspci -k | grep -A 2 -i "VGA"
```
2. 查看电脑默认使用的GPU

* About this computer
* 系统设置->Details

3. 系统设置->软件与更新->附加驱动

或通过如下方式打开
```
software-properties-gtk
```

4. nvidia-settings

Prime Profiles
```
sudo prime-select nvidia # 切换nvidia显卡
sudo prime-select intel  # 切换intel显卡
sudo prime-select query  # 查看当前使用的显卡
```
每次切换都需要重启才生效

### 6 问题汇总
**安装中的错误提示**:

1. Unable to load the kernel module 'nvidia-drm'

可能是因为之前驱动残留所致，nvidia.ko同上

2. Error：Unable to load the 'nvidia-drm' kernel module

在安装的最后一步没有提时安装成功，而是如上所示，应该是打开了Security BOOT选项

3. 检测到其它版本，同上卸载重新安装即可

4. the distribution-provided pre-install script failed!

驱动安装包本身的问题，可以直接继续

5. pkg-config` utility and the X.Org SDK/development package for your distribution and reinstall the driver.

安装时弹出X.org警告，可以忽略该警告

6. 安装完成后仍不能nvidia-smi，讲secure boot关闭即可

**其它问题**:

1. 循环登录

可以打开.xession-errors，根据错误日志的记录，解决对应的问题

安装时添加参数
```
sudo ./NVIDIA-Linux-x86_64-384.111.run -no-x-check -no-nouveau-check -no-opengl-files
```

完全卸载nvidia驱动方法，未验证如下:
```
sudo apt-get remove --purge nvidia-*
sudo apt-get install ubuntu-desktop
sudo rm /etc/X11/xorg.conf
echo 'nouveau' | sudo tee -a /etc/modules
```

## II cuda安装

### 1 安装流程

**下载合适的版本**

下载合适的[cuda](https://developer.nvidia.com/cuda-toolkit)版本，下载runfile(local)包

版本对应关系[文档](https://docs.nvidia.com/cuda/cuda-toolkit-release-notes/index.html)

* Documentation包含安装文档
* Release Notes附有cuda和driver版本对应表
* Lagacy Releases为其他版本

**注**：最好选择x.0版本，否则可能会出现库的调用问题

**选择runfile安装**

```
# Example 赋权限
sudo chmod +x cuda_9.1.85_387.26_linux.run
# 运行安装包
sudo ./cuda_9.1.85_387.26_linux.run
# 或
sudo ./cuda_9.1.85_387.26_linux.run --no
```

**注意**：cuda会提示安装nvidia驱动，如果已经安装了合适的驱动，此处选no，其他选项根据需要选取，默认库路径为/usr/local/cuda-version

**添加库文件路径**
在profile中添加（经测试），也可以在./bashrc
```
# 打开profile文件
sudo gedit /etc/profile
# 在文件末尾添加如下语句，注意version
export PATH=/usr/local/cuda-version/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda-version/lib64:$LD_LIBRARY_PATH
# 未验证
export PATH=/usr/local/cuda/bin:$PATH
# 使环境变量生效
source ~/.bashrc
# 未验证
sudo ldconfig -v
```

**重启并测试cuda**

```
# 测试cuda的samples
/usr/local/cuda-9.1/samples/1_Utilities/deviceQuery
路径下的实力程序，会输出设备信息
#查看cuda安装版本
nvcc -V
```

conda中的cudatoolkit只是nvidia安装的CUDA的部分文件，为了让普通需要CUDA的程序员能够在系统没有安装CUDA的时候也能运行，环境在安装的时候，自动安装了部分CUDA文件，的但是CUDA的其他文件可能没有，比如nvcc

因此完整的CUDA也需要安装，另外，如果驱动满足，这里的cudatoolkit版本不和系统一样，也能正常使用，cuDNN也是一样，conda自动安装了合适的版本

### 2 卸载cuda

安装目录默认在/usr/local/cuda，可用如下命令卸载：
```
sudo /usr/local/cuda-8.0/bin/uninstall_cuda-8.0.pl
```
再将文件夹残余清理掉即可


## III cudnn安装

### 1 下载

同样官网下载[CUDNN](https://developer.nvidia.com/rdp/cudnn-download)

outlook邮箱  Nvidia_num

下载cudnn需要登录，提供的两种安装方式：

1. cuDNN Library for linux 库文件压缩包
2. deb包：libcudnn、libcudnn-dev、libcudnn-doc

依赖库安装
```
sudo apt-get install libcupti-dev
```

### 2 库安装
#### library方式

解压后，只需要把inlude和lib64中的文件放在对应目录下即可

解压后，文件目录大致如下：
```
cuda/include/cudnn.h
cuda/NVIDIA_SLA_cuDNN_Support.txt
cuda/lib64/libcudnn.so
cuda/lib64/libcudnn.so.7
cuda/lib64/libcudnn.so.7.4.2
cuda/lib64/libcudnn_static.a
```

将头文件和库文件分别放到cuda目录下：
```
cp cuda/lib64/* /usr/local/cuda-10.0/lib64/
cp cuda/include/* /usr/local/cuda-10.0/include/
```

可以通过如下命令查看CUDNN的版本信息：
```
cat /usr/local/cuda/include/cudnn.h | grep CUDNN_MAJOR -A 2
```

未测试，另一种方式:

拷贝头文件和库文件，删除cuda/lib64下原有的软链接，在自己创建软链接

```
ln -s src dst
```

```
sudo cp ./cudnn/include/cudnn.h /usr/local/cuda/include/
sudo cp ./cudnn/lib64/lib* /usr/local/cuda/lib64/
# 软链接文件名把后边的具体版本号去掉
sudo ln -s /usr/local/cuda/lib64/libcudnn.so.5.1.10 /usr/local/cuda/lib64/libcudnn.so.5
sudo ln -s /usr/local/cuda/lib64/libcudnn.so.5 /usr/local/cuda/lib64/libcudnn.so
```
查看文件和软链接情况
```
ls -al /usr/local/cuda/lib64/libcudnn*
```

#### deb方式
```
sudo dpkg -i libcudnn7_7.0.3.11-1+cuda9.0_amd64.deb
sudo dpkg -i libcudnn7-dev_7.0.3.11-1+cuda9.0_amd64.deb
sudo dpkg -i libcudnn7-doc_7.0.3.11-1+cuda9.0_amd64.deb
```

该安装方式经测试，会把头文件放在/usr/include目录下，库文件在/usr/lib/x86_64-linux-gnu下

双击安装的话，其目录分别为/usr/local/cuda/include和/usr/local/cuda/lib64

### 3 cudnn安装验证

sample在/usr/src/cudnn_samples_v7目录下，通过mnistCUDNN验证

输出结果末尾有 Test passed，所名安装成功

### 4 cudnn卸载
```
# 直接删除路径下的库文件
sudo rm -rf /usr/local/cuda/include/cudnn.h
sudo rm -rf /usr/local/cuda/lib64/libcudnn*
```
