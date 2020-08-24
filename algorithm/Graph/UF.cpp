#include <iostream>
#include <vector>
using namespace std;


// 记录rank，可以保证层数
// Union 如果出现了 多次同rank的合并，深度还是会变大
class UnionFind {
public:
    UnionFind(int num) { 
        parent.resize(num);
        rank.resize(num);
        for (int i = 0; i < num; i++) {
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
};



// 简单很多的实现，但性能不如记录 rank 的

vector<int> parent;
// 递归实现
// 会把 index 到 其parent 路径上的所有节点的 parent 都改成 root
// 但如果 index 恰好是 root 或者 比较上层的，效果还是不好
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

int main()
{
    parent.resize(10);
    for (int i = 0; i < 10; ++i)  parent[i] = i;
    Union(0, 1);
    Union(1, 2);
    Union(2, 3);
    Union(3, 4);
    Union(4, 5);
    Union(6, 7);
    Union(7, 8);
    Union(8, 9);

    Union(0, 9);

    UnionFind UF(10);
    UF.Union(0, 1);
    UF.Union(1, 2);
    UF.Union(2, 3);
    UF.Union(3, 4);
    UF.Union(4, 5);
    UF.Union(6, 7);
    UF.Union(7, 8);
    UF.Union(8, 9);

    UF.Union(0, 9);

    system("pause");
    return 0;
}