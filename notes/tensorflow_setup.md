# I Tensorflow安装

## Anaconda

更换conda的镜像库，可以更快，但一些最新版本一般没有
```
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --set show_channel_urls yes
```
```
conda search tensorflow
```
安装

先激活要安装tensorflow的虚拟环境
```
conda install tensorflow
```
虽然可以安装很多版本，但是经过测试，conda安装时的版本是根据python版本的对应关系直接安装的

指定版本安装时发现如果不是推荐版本，无法安装

所以其安装时的自由度较低，只能通过更换python版本来实现更换tensorflow的目的（目前为止只找到了这个解决方案）

简单测试代码
```python
import tensorflow as tf
print(tf.__version__) # 版本信息
print(tf.__path__)  # 库安装路径
hello = tf.constant('Hello, TensorFlow!')
sess = tf.Session()
print(sess.run(hello))
```

tensorflow卸载
```
pip uninstall tensorflow
```

### pip

# II tensorRT安装




