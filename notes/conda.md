# anaconda命令
## 换源、更新、卸载
## 换源
* 1 对anaconda换源，更换成清华的源：

[清华大学开源软件镜像站](mirrors.tuna.tsinghua.edu.cn)
[中科大源](mirrors.ustc.edu.cn)

```
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/pytroch/

# 或在~/.condarc中
channels:
    - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
    - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
    - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/
    - https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/pytroch/
ssl_verify: true
```

如要换回conda的默认源，直接删除channels即可：

```
conda config --remove-key channels
```

* 2 设置显示源地址：
```
conda config --set show_channel_urls yes
```
* 3 使能condrc文件：
```
source ~/.condarc
```
* 4 更新conda自己：
```
conda update conda
```
* 5 更新所有库：
```
conda update --all
```
* 6 卸载：
```
conda install anaconda-clean
```

## 环境管理
查看帮助
```
conda env --help
```
创建新环境
```
# 环境名 snowflakes 该环境的软件包 biopython
conda create --name snowflakes biopython
# 创建时指定python版本
# 可以用package_name=version_number形式指定软件包版本
conda create --name bunnies python=3 astroid babel
```
复制环境
```
# 添加参数--clone，指定相应的环境名即可
conda create --name flowers --clone snowflakes
```
配置文件
```
# 导出环境
conda env export --name snowflakes > snowflakes.yml
# 导入环境
conda env create -f snowflakes.yml
```
删除环境
```
conda remove --name [env-name] --all
conda env remove --name [env-name]
```
查看环境
```
# 查看该环境，此处envs指所有
conda info --envs
# 查看环境列表
conda env list
```
查看指定环境下的软件包
```
conda list --name [name]
```
切换环境
```
切换
source activate snowflakes
切回默认
source deactivate
```


## 软件包管理
查看所有已安装的软件包
```
conda list
```
查找软件包，罗列所有可用版本，已安装前有*标记
```
conda search beautifulsoup4
```
安装软件包

或在[官网](http://anaconda.org)搜索软件包
```
# conda包管理
conda install --name beautifulsoup4=4.4.1
# pip包管理
pip install xxx
```
更新软件包
```
conda update --name snowflakes beautifulsoup4=4.5.1
```
添加下载更新工具包的其它源
```
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --set show_channel_urls yes
conda install numpy   #测试是否添加成功
```
