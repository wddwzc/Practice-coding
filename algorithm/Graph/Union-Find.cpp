#include <iostream>
#include <vector>
using namespace std;

// 并查集
// 对于不需要给出路径的连通性判断，很有效
class UF
{
public:
    // 以整数标识(0到N-1)初始化N个触点
    UF(int N);
    // 在p和q之间添加一条链接
    void union_(int p, int q);
    // p(0到N-1)所在的分量的标识符
    int find(int p);
    // 如果p和q存在于同一个分量中则返回true
    bool connected(int p, int q);
    // 连通分量的数量
    int Count();

private:
    // 数组id
    vector<int> id;
    // 连通分量的个数
    int count;
};

UF::UF(int N) {
    count = N;
    id.resize(N);
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }
}

// 将p和q归并到相同的分量中
void UF::union_(int p, int q) {
    int pID = find(p);
    int qID = find(q);

    // 如果p和q已经在相同的分量中，不需要归并
    if (pID == qID)  return;

    // 遍历，将p的分量归到q
    for (int i = 0; i < id.size(); ++i) {
        if (id[i] == pID)  id[i] = qID;
    }
    --count;
}

// quick-find算法
int UF::find(int p) {
    return id[p];
}

bool UF::connected(int p, int q) {
    return find(p) == find(q);
}

int UF::Count() {
    return count;
}

int main() {
    int N = 10;
    UF uf(N);
    return 0;
}