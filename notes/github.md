# Github
## 一 提交至git
### 本地工作由git维护三棵树
1. working dir：工作目录
2. 缓存区index：缓存区域，临时保存改动
3. HEAD区：最近提交后的结果

### 基本流程
#### 获取git仓库
1. git init
将创建一个名为 .git 的子目录，这个子目录含有你在初始化的Git仓库中所有的必须文件。但是，我们只是做了一个初始化的操作，你的项目里的文件还没有被跟踪。

2. 



#### git add 提交到本地仓库
git add [参数] <路径>

将working dir工作区中的文件添加到index暂存区，就是告诉git系统，我们要提交哪些文件，之后就可以使用git commit命令进行提交了

* git add .
无参数默认为将**修改**的文件和**未跟踪新添加**的文件添加到git系统的暂存区（注：不包括删除）

* git add -u .
表示将已跟踪文件中的**修改**和**删除**的文件添加到暂存区，不包括新增加的文件（注：被删除的文件被加入到暂存区再被提交并推送到服务器的版本库之后这个文件就会从git系统中消失了）

* git add -A .
表示将所有的已跟踪的文件的修改与删除和新增的未跟踪的文件都添加到暂存区（所有）

#### git commit 提交历史至HEAD并记录
git commit

将暂存区里的改动给提交到本地的版本库，生成一个40位的哈希值commit-id，用于版本回退

* git commit -m 'message'
-m参数表示可以直接输入后面的“message”，如果不加-m参数，回调用vim来输入message

* git commit -am ‘message’ -am等同于-a -m
-a参数可以将所有已跟踪文件中的执行修改或删除操作的文件都提交到本地仓库，即使它们没有经过git add添加到暂存区，注意: 新加的文件（即没有被git系统管理的文件）是不能被提交到本地仓库的。


### 提交历史至HEAD并记录
* 命令：commit
* 示例：a1添加进index区后，使用git commit a1可进行提交
* 如果询问身份，用git config 名字和邮箱 提交

#### git push 推送到服务器
git push <远程主机名> <本地分支名> <远程分支名>

将本地版本库的分支推送到远程服务器上对应的分支

* git push origin master
如果远程分支被省略，如上则表示将本地分支推送到与之存在追踪关系的远程分支（通常两者同名），如果该远程分支不存在，则会被新建
* git push origin :refs/for/master
如果省略本地分支名，则表示删除指定的远程分支，因为这等同于推送一个空的本地分支到远程分支，等同于 git push origin –delete master
* git push origin
如果当前分支与远程分支存在追踪关系，则本地分支和远程分支都可以省略，将当前分支推送到origin主机的对应分支
* git push
如果当前分支只有一个远程分支，那么主机名都可以省略，形如 git push，可以使用git branch -r ，查看远程的分支名


### 简单git操作
提交到master，不是分支
```
git status 查看工作区代码相对于暂存区的差别
git add . 将当前目录下修改的所有代码从工作区添加到暂存区，代表当前目录
git commit -m ‘注释’ 将缓存区内容添加到本地仓库
git pull origin master先将远程仓库master中的信息同步到本地仓库master中
git push origin master 将本地版本库推送到远程服务器，origin是远程主机，master表示是远程服务器上的master分支，分支名是可以修改的
```

```
git add .   // 将修改添加至本地缓存；如果想添加某个特定的文件，只需把.换成特定的文件名即可
git commit -m 'commit description'   // 将本地缓存办存到本地仓库中
git remote add origin ssh地址/https地址   //将本地的仓库关联到github上
git push -u origin master   // 将本地仓库推送至服务器
git pull origin master    // 将服务器的代码更新到本地仓库中
```

### 查看文件状态
* git status -s 产看简短信息
* git status  查看所有信息
查看文件是否被git接管，红色为未接管，绿色为已接管

### 历史版本恢复
* 产看修改的过程：git log

让HEAD回溯
* 返回某一步过程：git reset “前六位过程码”

硬盘也做修改，慎用
* git reset --hard "前六位过程码"


## 二 分支管理
### 查看分支

* 查看本地分支 git branch
* 查看远程分支 git branch -r
* 查看所有分支 git branch -a

### 本地创建新分支

* 命令：git branch branch_name
* 示例：git branch test-name

### 切换到新分支

* 命令：git checkout branch_name
* 例子：git checkout test-name

### 创建并切换分支

* git checkout -b branch_name

相当于：

* git branch branch_name
* git checkout branch_name

### 将新分支推送到github

* 命令：git push origin branch_name
* 示例：git push origin test-name

### 删除本地分支

* 命令：git branch -d branch_name
* 示例 git branch -d test-name

### 删除github远程分支

* 命令：git push origin :branch_name
* 示例：git push origin :test-name
