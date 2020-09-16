/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end






// hash + 双向链表
// 直接用 list 做的
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
                temp[1] = value;
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




class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (keys.count(key)) {
            if (key != data.front()[0]) {
                move2head(key);
            }
            return data.front()[1];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keys.count(key)) {
            if (key != data.front()[0]) {
                move2head(key);
            }
            data.front()[1] = value;
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

    void move2head(int key) {
        vector<int> temp = *(keys[key]);
        data.erase(keys[key]);
        data.push_front(temp);
        keys[key] = data.begin();
    }

    unordered_map<int, list<vector<int>>::iterator> keys;
    list<vector<int>> data;
    int cap;
};






// 自己写一个双向链表
// 然后 hash 做指针索引
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};