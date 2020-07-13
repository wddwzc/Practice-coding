## 初级排序算法

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

## 归并排序

基于**归并**这个简单的操作：将两个有序的数组归并成一个更大的有序数组

一种简单的递归排序算法： 归并排序

时间复杂度：O(NlogN)

空间复杂度：O(N)  缺点