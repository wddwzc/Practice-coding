# PKG install
## dpkg
apt-get是Debian系统下进行软件管理的工具，可以安装和卸载软件包。

安装软件 apt-get install softname

删除软件包，但是不删除软件的配置文件：apt-get remove softname 如果再想安装，可能会出现问题。

删除软件包，并删除相应的配置文件：apt-get remove --purge softname

apt-get autoremove softname将依赖的软件包卸载掉，这样就可以完全卸载一个软件。

可以用 softname -V来检查是否卸载完成

更新软件信息数据库 apt-get update

进行系统升级 apt-get upgrade

搜索软件包： apt-cache search



Deb软件包相关安装与卸载
安装deb软件包
命令： dpkg -i xxx.deb
删除软件包
命令：  dpkg -r xxx.deb
连同配置文件一起删除
命令： dpkg -r --purge xxx.deb
查看软件包信息
命令： dpkg -info xxx.deb
查看文件拷贝详情
命令： dpkg -L xxx.deb
查看系统中已安装软件包信息
命令： dpkg -l
