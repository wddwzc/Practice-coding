# ros & anaconda

## 兼容问题

查看python指令的软链接指向的可执行程序
```
cd /usr/bin
ls -l python
ls -l python3
```

anaconda的目录一般为 ~/anaconda3/bin

可能出现的编译问题如下：

### 1. error: /home/wzc/anaconda3/lib/libfontconfig.so.1: undefined reference to 'FT_Done_MM_Var'

查看libfontconfig.so.1软链接，应该是版本不对应导致的的问题
```
/usr/lib/x86_64-linux-gnu$ ll | grep libfontconfig.so.1
lrwxrwxrwx   1 root root        22 8月  17  2016 libfontconfig.so -> libfontconfig.so.1.9.0
lrwxrwxrwx   1 root root        22 11月 27 20:55 libfontconfig.so.1 -> libfontconfig.so.1.9.0
-rw-r--r--   1 root root    273832 8月  17  2016 libfontconfig.so.1.9.0

~/anaconda3/lib$ ll | grep libfontconfig.so.1
lrwxrwxrwx  1 wzc wzc       23 11月 28 20:59 libfontconfig.so -> libfontconfig.so.1.11.1*
lrwxrwxrwx  1 wzc wzc       23 11月 28 20:59 libfontconfig.so.1 -> libfontconfig.so.1.11.1*
-rwxrwxr-x  1 wzc wzc   324384 11月 28 20:59 libfontconfig.so.1.11.1*
```

所以将anaconda3下的软链接，链接到正确的版本即可
```
1.
copy the file from /usr/lib/x86_64-linux-gnu to ~/anaconda3/lib
2.
~/anaconda3/lib$ ln -s libfontconfig.so.1.10.1 libfontconfig.so.1
~/anaconda3/lib$ ln -s libfontconfig.so.1.10.1 libfontconfig.so

The final display is as follows:
~/anaconda3/lib$ ll | grep libfontconfig
-rw-rw-r--  1 wzc wzc   494654 11月 28 20:59 libfontconfig.a
-rwxrwxr-x  1 wzc wzc     1231 11月 28 20:59 libfontconfig.la*
lrwxrwxrwx  1 wzc wzc       22 12月 10 16:13 libfontconfig.so -> libfontconfig.so.1.9.0
lrwxrwxrwx  1 wzc wzc       22 12月 10 16:13 libfontconfig.so.1 -> libfontconfig.so.1.9.0
-rwxrwxr-x  1 wzc wzc   324384 11月 28 20:59 libfontconfig.so.1.11.1*
-rw-r--r--  1 wzc wzc   273832 8月  17  2016 libfontconfig.so.1.9.0
```



```
~/ros_ws/my_ws$ rosrun pyeg talker.py
Traceback (most recent call last):
  File "/home/wzc/ros_ws/my_ws/src/pyeg/scripts/talker.py", line 39, in <module>
    import rospy
  File "/opt/ros/kinetic/lib/python2.7/dist-packages/rospy/__init__.py", line 49, in <module>
    from .client import spin, myargv, init_node, \
  File "/opt/ros/kinetic/lib/python2.7/dist-packages/rospy/client.py", line 52, in <module>
    import roslib
  File "/opt/ros/kinetic/lib/python2.7/dist-packages/roslib/__init__.py", line 50, in <module>
    from roslib.launcher import load_manifest
  File "/opt/ros/kinetic/lib/python2.7/dist-packages/roslib/launcher.py", line 42, in <module>
    import rospkg
ModuleNotFoundError: No module named 'rospkg'
```


```
$ conda install setuptools
$ pip install -U rosdep rosinstall_generator wstool rosinstall six vcstools
```
