[TOC]

# 排序

## 1 初级排序算法

### 规则

**排序算法类模板**中的example展示了习惯约定

```c++
class Example
{
public:
    static void sort(Comparable[] a) {
        /* 算法流程 */
    }
    static boolean isSorted(Comparable[] a) {
        // 测试数组元素是否有序
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i-1])) 
                return false;
        return true;
    }
    public static void main(String[] args) { 
        // 从标准输入读取字符串，将它们排序并输出
        String[] a = In.readStrings();
        sort(a);
        assert isSorted(a);
        show(a);
    }

private:
    static boolean less(Comparable v, Comparable w){ 
        return v.compareTo(w) < 0;
    }
    static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j]; a[j] = t;
    }
    static void show(Comparable[] a) {
        // 在单行中打印数组
        for (int i = 0; i < a.length; i++)
            StdOut.print(a[i] + " ");
        StdOut.println();
    }
};
```


### 选择排序

找到数组中最小/最大的那个元素，其次，将它和数组的第一个元素交换位置

时间复杂度：N(N-1)/2次比较，N次交换；O(N^2)

空间复杂度：O(1)

特点：运行时间和输入无关；数据移动最少O(N)(其他基本都是线性对数或平方级)

### 插入排序

将每一个元素插入到其他已经有序的元素中的适当位置

时间复杂度：取决于初始顺序

空间复杂度：O(1)

特点：对于有序或部分有序的数据，效率很高

部分有序：数组中倒置的数量小于数组大小的某个倍数

- 数组中每个元素距离它的最终位置都不远
- 一个有序的大数组接一个小数组
- 数组中只有几个元素的位置不正确

改进：只需要在内循环中将较大的元素都向右移动而不总是交换
两个元素（这样访问数组的次数就能减半）

请见练习 2.1.25

### 希尔排序

权衡了子数组的规模和有序性

基于插入排序的快速的排序算法，改善了对大规模乱序的性能

使数组中任意间隔为 h 的元素都是有序的，成为**h有序数组**

性能无法准确描述：低于O(N^2)，大致为O($N^{3/2}$)

空间复杂度：O(1)

递增序列如何选取：不仅取决于h

在希尔排序中为什么在实现 h 有序时不使用选择排序？

## 2 归并排序

基于**归并**这个简单的操作：将两个有序的数组归并成一个更大的有序数组

一种简单的递归排序算法： 归并排序（分治思想）

时间复杂度：O(NlogN)

空间复杂度：O(N)  缺点

特点：处理大规模数据，需要辅助数组

改进：

- 用不同的方法处理小规模问题能改进大多数递归算法的性能，在小规模情况时（如长度小于15）用基础排序
- 测试数据是否有序，如果a[mid]小于等于a[mid+1]，则不需要merge
- 不适用辅助空间：通过交换辅助数组和输入数组的属性，跳过重复赋值这一步

自顶向下：

自底向上：适合链式存储

## 3 快速排序

一种**分治**的排序算法

快速排序将数组排序的方式则是当两个子数组都有序时整个数组也就自然有序了

时间复杂度：O(NlogN)

特点：原地排序，时间复杂度低，比较次数比较少

注意事项：

- 原地切分：如果用辅助数组会很容易，但开销会很大
- 别越界：如果切分数组是最大或最小的元素，小心指针越界问题
- 保持随机性：随机选择切分元素
- 终止循环：注意循环结束条件和指针越界判断
- 切分元素重复的情况：左侧做好遇到>=停，右侧遇到<=停
- 终止递归：如切分元素放入正确位置

改进：

- 切换到插入排序：对于小数组，插入排序更快；对小数组，快排也会递归
- 三取样切分：去小部分的中位数为split，3是个经验值
- 熵最优排序：三向切分解决大量重复元素的数组，降到了线性N

## 4 优先队列

两种关键操作：删除最大元素；插入元素

### 基本API

```c++
Class MaxPQ
{
public:
    void MaxPQ();
    MaxPQ(int max);
    MaxPQ(Key[] a);
    void insert(Key v);
    Key max();
    Key delMax();
    bool isEmpty();
    int size();
}
```

MaxPQ和MinPQ的转换很简单

从N个输入中找到最大的M个元素：

* 排序算法：O(NlogN)
* 初级实现的优先队列：O(NM)
* 基于堆实现的优先队列列：O(NlogM)

### 初级实现

**数组实现（无序）**：将最大元素和边界元素交换然后删除

**数组实现（有序）**：insert()中添加代码，较大元素右移，则back()就是最大

**链表表示法**：基于链表的下压栈

### 堆的定义

当一棵二叉树的每个结点都大于等于它的两个子结点时，它被称为堆有序

大顶堆：每个节点都小于它的父节点，根节点是最大节点

**二叉堆表示法**

如果采用链式表示法，每个节点需要3个指针

如果使用**完全二叉树**，接可以用**数组**表示，按照**层级顺序**放入数组，根节点在位置1

一般**堆**指的就是数组表示的**二叉堆**

可实现操作：插入元素、删除最大元素

特点：

* 第k个节点的叶子节点2k和2k+1
* 第k个节点的父节点k/2
* 大小为N的完全二叉树高度[lgN]（去尾）
* 索引最好从1开始，方便计算

**堆的算法**

```c++
class MaxPQ
{
public:
    MaxPQ(int maxN) {
        pq = vector<int>(maxN);
    }
    bool isEmpty() {
        return N == 0;
    }
    int size() {
        return N;
    }
    void insert(int v) {
        pq.push_back(v);
        ++N;
        swim(N);
    }
    int delMax() {
        int max = pq[1];
        exch(1, N--);
        sink(1);
        return max;
    }

private:
    vector<int> pq;
    int N = 0;
    void less(int i, int j) {
        return pq[i] < pq[j];
    }
    void exch(int i, int j) {
        int t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }
    void swim(int k) {
        while (k > 1 && less(k/2, k)) {
            exch(k/2, k);
            k = k / 2;
        }
    }
    void sink(int k) {
        while (2 * k <= N>) {
            int j = 2 * k;
            if (j < N && j + 1 < N && less(j, j + 1))  j++;
            if (!less(k, j))  break;
            exch(k, j);
            k = j;
        }
    }
}
```

- **上浮 swim**：由下至上的堆有序变化，节点优先级上升（或在堆低加入了新元素）
- **下沉 sink**：由上至下的堆有序变化，父节点比子节点小，需要下沉调整
- **插入元素**：新元素加到末尾，增加堆大小，让新元素上浮
- **删除最大元素**：从数组顶删去最大元素，并将最后元素置于顶，减小堆大小，并下沉

插入元素和删除最大元素可以保证在logN
