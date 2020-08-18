### 实践问题
pose_estimation_3d2d运行时报错：
error while loading shared libraries: libg2o_core.so: cannot open shared object file: No such file or directory

主要的问题在于：系统默认的路径是lib或者usr/lib，而g2o安装后库文件是在usr/local/lib里面，所以需要配置路径。

配置方式：

在etc文件夹下找到ld.so.conf文件，将指定路径加在下一行：

/usr/local/lib

或者在etc/ld.so.conf.d/文件夹下touch一个新.conf命名的文件，在这个文件中vim上面的路径。（推荐这个方法）

注意：以上命令需要加sudo，否则权限不够。

最后，终端输入：sudo /sbin/ldconfig或sudo ldconfig完成配置。
