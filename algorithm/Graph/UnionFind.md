
简单的并查集

```c++
class UnionFind {
    // 构造参数：顶点个数 （直接初始化一个数组就行）
    UnionFind(num) { 
        parent.resize(num);
        for (let i = 0; i < num; i++) {
            parent[i] = i;
        }
    }
    int findRoot(int x) { // 找出顶点x的根节点
        int x_root = x;
        while (parent[x_root] !== x_root) { // 一直找父节点，找到尽头
            x_root = parent[x_root];
        }
        return x_root; // 返回根节点
    }
    // 这里是把 x 连向 y
    void union(x, y) { // 把顶点x和顶点y所在的集合合并到一起
        int x_root = findRoot(x)
        int y_root = findRoot(y)
        if (x_root === y_root) return
        roots[x_root] = y_root // x的根节点指向y的根节点，就合并了两个树
        return;
    }
    vector<int> parent;
}
```

以上实现方法存在一些缺陷：

* 没有考虑路径长度的问题，比如 x 所在的树很高，y 所在的树很低，合并时：
* 让 x_root 指向 y_root 会导致树的高度变大，导致 find 的效率变慢

解决方法：

再维护一个 ranks 数组，记录根节点所在的树的树高度，谁所在的树更高，则其根节点作为合并后的根节点

这样的话，每次添加的时候都会比较rank，把rank小的连到rank大的上边，就可以保证 rank < 3

```c++
class UnionFind {
    UnionFind(num) { 
        parent.resize(num);
        rank.resize(num);
        for (let i = 0; i < num; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findRoot(int x) {
        int x_root = x;
        while (parent[x_root] != x_root) {
            x_root = parent[x_root];
        }
        return x_root;
    }
    void Union(int x, int y) { // 把顶点x和顶点y所在的集合合并到一起
        int x_root = findRoot(x);
        int y_root = findRoot(y);
        if (x_root == y_root) return;  // 已经同处于一个集合了
        int x_rank = rank[x_root];
        int y_rank = rank[y_root];
        // 谁高度大，谁就作为根节点，由于根的rank是大的，所以连接以后，rank不变
        if (x_rank < y_rank) {    
            parent[x_root] = y_root ;
        } else if (y_rank < x_rank) {
            parent[y_root] = x_root;

        // 一样高，谁作为根节点都行，但是根节点的 rank 需要+1
        } else {                  
            parent[y_root] = x_root;
            rank[x_root]++;
        }
        return;
    }
    vector<int> parent;
    vector<int> rank;
}
```


改进的find方法，如下（调试见 UF.cpp）：

```c++
// 递归
int find(int index) {
    if (parent[index] != index) {
        parent[index] = find(parent[index]);
    }
    return parent[index];
}
// 把 x_root 连到 y_root 上
void Union(int x, int y) {
    // parent[find(x)] = find(parent[y]);
    parent[find(x)] = find(y);
    return;
}
```
