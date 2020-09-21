[TOC]

https://www.pianshen.com/article/3434326771/


https://zhuanlan.zhihu.com/p/26307123


https://blog.csdn.net/leonardohaig/article/details/104570965



# RANSAC

以 Line Fitting 为例

算法流程：

1. 解出模型所需最小点集（随机取两个点，直线拟合需要两个）
2. 解的模型
3. 计算每个点的error function（计算点到直线的距离）
4. 记同意该模型的点数，即内点数量（d < $\tau$）
5. 重复1-4，N次迭代

## 参数选择

**1 距离阈值** $\tau$

卡方分布：如果单个距离满足高斯分布，k个相互独立的高斯分布的平方之和



经验值

**2 迭代次数** N

概率p：至少能得到一次sample里不含outlier

p=0.99，计算N

相关参数：

- e：outlier比例
- s：sample中点的数量（直线是2个）
- N：采样次数
- p：获得至少一次good sample的概率

由 $(1-(1-e)^s)^N = 1 - p$ 可得 $N = \frac{log(1-p)}{log(1-(1-e)^s)}$

对不同的s和e，可以计算出一个N的table

## 实用技巧

**1 提前终止**

有一个期望的inlier ratio：1-e

如果某次迭代内点比例达到了期望的值，直接提前跳出

**2 LSQ最小二乘**

每次筛选出inlier和outlier以后，用LSQ再拟合一边model，让model更准

## 总结

优点：简单、普遍；inlier比例很小也可能work

缺点：需要确定 $\tau$；inlier ration低的话，N很大