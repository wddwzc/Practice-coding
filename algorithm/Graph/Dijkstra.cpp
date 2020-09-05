// 迪杰斯特拉 针对 有向无环图

#include <iostream>
#include <vector>
using namespace std;

/* n是总的结点数, v是出发结点, dist是v到此的最短距离, pre前一个结点, graph是结点间的权值 */
void Dijkstra(int n, int v, vector<int> &dist, vector<int> &pre, vector<vector<int>> &graph) {
    vector<bool> visited(n + 1, false);
    // 更新起始点 v 到相邻点的 dist 和 pre
    for (int i = 1; i <= n; i++) {
        dist[i] = graph[v][i];
        if (dist[i] < INT_MAX)  pre[i] = v;
        else                    pre[i] = 0;
    }
    dist[v] = 0;
    visited[v] = true;
    //总的迭代次数
    for (int i = 2; i <= n; i++) {
        // 找到最小的距离对应的节点 best
        int best = v;
        int min_weight = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min_weight) {
                min_weight = dist[j];
                best = j;
            }
        }
        visited[best] = true;

        // 更新dist和pre
        for (int j = 1; j <= n;j++) {
            if (!visited[j] && graph[best][j] != INT_MAX) {
                int newdist = dist[best] + graph[best][j];
                if (newdist < dist[j]) {
                    dist[j] = newdist;
                    pre[j] = best;
                }
            }
        }
    }
}


// pre 前一节点  start 起始节点  end 终止节点
void printpath(vector<int> pre, int start, int end) {
    int temp = end;
    vector<int> path;
    while (temp != start) {
        path.push_back(temp);
        temp = pre[end];
        end = temp;
    }

    // 输出
    cout << start << "->";
    for (int i = path.size(); i > 1;i--) {
        cout << path[i-1] << "->";
    }
    cout << path[0];
    path.clear();
}


int main()
{
    int n_node, n_edge;
    // 节点数 和 边数
    cin >> n_node >> n_edge;
    vector<vector<int>> graph(n_node + 1, vector<int>(n_node + 1, INT_MAX));
    for (int i = 1; i <= n_node; i++) {
        for (int j = 1; j <= n_node; j++)
            graph[i][j] = INT_MAX;
    }
    int from, to, weight;
    for (int i = 1; i <= n_edge; ++i) {
        cin >> from >> to >> weight;
        if (weight < graph[from][to]) {  // 有重边
            graph[from][to] = weight;    // from 指向 to
            // graph[to][from] = weight;    // to 指向 from，这样表示无向图
        }
    }
    // dist 存最短距离   pre 是最短路径的父节点
    vector<int> dist(n_node + 1), pre(n_node + 1);
    for (int i = 1; i <= n_node; ++i)
        dist[i] = INT_MAX;
    Dijkstra(n_node, 1, dist, pre, graph);
    cout << "the min distance from 1 to n: " << dist[n_node] << endl;
    printpath(pre, 1, n_node);
    system("pause");
    return 0;
}

/*
6 7
1 2 3
1 3 7
2 4 4
3 4 2
3 5 2
4 6 5
5 6 2
*/



/*
6 7
1 2 3
1 4 7
2 3 4
3 6 5
4 3 2
4 5 2
5 6 2
*/