# 基础语法
### 编码
源文件默认UTF-8，字符串为unicode字符串，但可自行指定：
```python
# -*- coding: cp-1252 -*-
```
### 标识符
* 以字母或下环线开头
* 其他部分为字母、数字、下划线
* 大小写敏感
允许非ASCII标识符

# 脚本式编程
```
脚本顶部添加如下命令：
#! /usr/bin/env python3
修改脚本权限，使其有执行权限：
$ chmod +x hello.py
执行脚本：
./hello.py
```

# 注释
```python
# 这是一个注释
```
asdfasdf
```
"""
asdfasdfasdf
"""
```

# 软件包

## argparse

```py
# 导入模块
import argparse
# 创建一个解析对象，description 参数可以用于插入描述脚本用途的信息，可以为空
parser = argparse.ArgumentParser(description="your script description")
# 向该对象中添加你要关注的命令行参数和选项
parser.add_argument()
# 解析参数
parser.parse_args()
# 解析已有参数，未处理参数会保留
parser.parse_known_args()
```

* argparse 会自动生成帮助信息，-h或--help

* add_argument: 
```py
add_argument(
    'i'     # 位置参数，是必须参数
    '-i'    # 可选参数，长短两种形式可并存
    '--info'
    action=“store_true” # 如果该参数存在为true，否则为false
    required=true   # true表示必须参数
    type=int    # 类型，默认str
    nargs=2     # 参数数量，+至少一个，?最多一个
    choices=[0,1,2] # 可选值
    default=1       # 默认值
    dest=“information”  # 存放value的属性名
    help=“the information”  # 帮助，参数说明
)

# 添加互斥组
group = parser.add_mutually_exclusive_group()
group.add_argument("-v", "--verbose", action="store_true")
group.add_argument("-q", "--quiet", action="store_true")
```


## os.path模块
os.path.abspath(path) #返回绝对路径
os.path.basename(path) #返回文件名
os.path.commonprefix(list) #返回list(多个路径)中，所有path共有的最长的路径。
os.path.dirname(path) #返回文件路径
os.path.exists(path)  #路径存在则返回True,路径损坏返回False
os.path.lexists  #路径存在则返回True,路径损坏也返回True
os.path.expanduser(path)  #把path中包含的"~"和"~user"转换成用户目录
os.path.expandvars(path)  #根据环境变量的值替换path中包含的”$name”和”${name}”
os.path.getatime(path)  #返回最后一次进入此path的时间。
os.path.getmtime(path)  #返回在此path下最后一次修改的时间。
os.path.getctime(path)  #返回path的大小
os.path.getsize(path)  #返回文件大小，如果文件不存在就返回错误
os.path.isabs(path)  #判断是否为绝对路径
os.path.isfile(path)  #判断路径是否为文件
os.path.isdir(path)  #判断路径是否为目录
os.path.islink(path)  #判断路径是否为链接
os.path.ismount(path)  #判断路径是否为挂载点（）
os.path.join(path1[, path2[, ...]])  #把目录和文件名合成一个路径
os.path.normcase(path)  #转换path的大小写和斜杠
os.path.normpath(path)  #规范path字符串形式
os.path.realpath(path)  #返回path的真实路径
os.path.relpath(path[, start])  #从start开始计算相对路径
os.path.samefile(path1, path2)  #判断目录或文件是否相同
os.path.sameopenfile(fp1, fp2)  #判断fp1和fp2是否指向同一文件
os.path.samestat(stat1, stat2)  #判断stat tuple stat1和stat2是否指向同一个文件
os.path.split(path)  #把路径分割成dirname和basename，返回一个元组
os.path.splitdrive(path)   #一般用在windows下，返回驱动器名和路径组成的元组
os.path.splitext(path)  #分割路径，返回路径名和文件扩展名的元组
os.path.splitunc(path)  #把路径分割为加载点与文件
os.path.walk(path, visit, arg)  #遍历path，进入每个目录都调用visit函数，visit函数必须有
3个参数(arg, dirname, names)，dirname表示当前目录的目录名，names代表当前目录下的所有
文件名，args则为walk的第三个参数
os.path.supports_unicode_filenames  #设置是否支持unicode路径名


输出尺寸=(输入尺寸-filter尺寸+2*padding)/stride+1


./train.py -d /home/wzc/Data/kitti/data_odometry_laser -ac ./config/arch/squeezeseg_crf.yaml -dc ./config/labels/semantic-kitti.yaml -l /home/wzc/Project/log -p /home/wzc/Data/RangeNet/Pre-trained/squeezeseg-crf

同Googlenet主要由Inception module组成或Resnet主要由Residual learning block组成一样，构成SqueezeNet网络的主要模块是Fire module。

它主要由两部分构成，分别为squeeze layer与expand layer。其中squeeze layer为1x1的conv layer，主要用于将输入此module的input channels数目进行缩减；而expand layer包含1x1的conv layer与3x3的conv layer，主要用于真正的feature maps的特征再融合，再表达。详细的fire module可见下图所示。

在下表中，我们能看出通过与Alexnet相比较，SqueezeNet展示了其在使用当下已成熟的model compression技术前后所具有的性能及参数大小优势。它进一步表明了当下较为成熟的像model prunning/model compression/low bit quantization等技术都可用于像SqueezeNet这样的小CNN models。

作者在原来的SqueezeNet网络中引入了Residual network里面提的by-pass learning的思想。但因为当ic != oc时不能直接使用简单的identity-mapping，因此在某些modules上考虑引入了1x1的conv使得ic == oc。这样作者共设计了两种考虑了residual learning的网络变形。具体网络结构可见上面章节的图中，下图所示则为三种网络结果对比分别具有的accuracy及模型参数大小。


