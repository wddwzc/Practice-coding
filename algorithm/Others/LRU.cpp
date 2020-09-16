#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (keys.count(key)) {
            if (key != data.front()[0]) {
                vector<int> temp = *(keys[key]);
                data.erase(keys[key]);
                data.push_front(temp);
                keys[key] = data.begin();
            }
            return data.front()[1];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keys.count(key)) {
            if (key != data.front()[0]) {
                vector<int> temp = *(keys[key]);
                data.erase(keys[key]);
                data.push_front(temp);
                keys[key] = data.begin();
            }
            else {
                data.front()[1] = value;
            }
        }
        else {
            if (data.size() >= cap) {
                keys.erase(data.back()[0]);
                data.pop_back();
            }
            data.push_front({key, value});
            keys[key] = data.begin();
        }
    }

    unordered_map<int, list<vector<int>>::iterator> keys;
    list<vector<int>> data;
    int cap;
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得关键字 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得关键字 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
    system("pause");
    return 0;
}