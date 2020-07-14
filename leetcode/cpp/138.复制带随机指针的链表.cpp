/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// O(1)空间的迭代
// 用新旧链表交替的方式，实现了类似与map<node*, node*>的功能
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr = head;
        Node *medium = nullptr;
        if(head == nullptr)
            return nullptr;
        //创建相邻结点
        // 形成了old1-new1-old1-new1穿插相连的链表，但new的random是nullptr
        while(ptr != nullptr) {
            medium = ptr->next;
            ptr->next = new Node(ptr->val);//ptr后创建新结点
            ptr->next->next = medium;
            ptr = ptr->next->next;
        }
        //遍历新链表，修改新结点的random指针
        ptr = head;
        while(ptr != nullptr) {
            // 当前是old->old非空
            if(ptr->random != nullptr) {
                // old1->new1->random = old1->oldn->newn;
                ptr->next->random = ptr->random->next;
            }
            else { 
                // 当前old->random为空
                ptr->next->random = nullptr;
            }
            // 跳到下一个old
            ptr = ptr->next->next;
        }
        // 把old和new分开
        Node* ptr_old_list = head;
        Node* ptr_new_list = head->next;
        Node *result = head->next;
        while(ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next;
            if(ptr_new_list->next != nullptr)
                ptr_new_list->next = ptr_new_list->next->next;
            else
                ptr_new_list->next = nullptr;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return result;
    }
};
// @lc code=end


// 类比图的DFS
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        if (visited.count(head))  return visited[head];
        Node *new_node = new Node(head->val);
        visited.insert({head, new_node});
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
    unordered_map<Node*, Node*> visited;
};


// O(1)空间的迭代
// 用新旧链表交替的方式，实现了类似与map<node*, node*>的功能
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr = head;
        Node *medium = nullptr;
        if(head == nullptr)
            return nullptr;
        //创建相邻结点
        // 形成了old1-new1-old1-new1穿插相连的链表，但new的random是nullptr
        while(ptr != nullptr) {
            medium = ptr->next;
            ptr->next = new Node(ptr->val);//ptr后创建新结点
            ptr->next->next = medium;
            ptr = ptr->next->next;
        }
        //遍历新链表，修改新结点的random指针
        ptr = head;
        while(ptr != nullptr) {
            // 当前是old->old非空
            if(ptr->random != nullptr) {
                // old1->new1->random = old1->oldn->newn;
                ptr->next->random = ptr->random->next;
            }
            else { 
                // 当前old->random为空
                ptr->next->random = nullptr;
            }
            // 跳到下一个old
            ptr = ptr->next->next;
        }
        // 把old和new分开
        Node* ptr_old_list = head;
        Node* ptr_new_list = head->next;
        Node *result = head->next;
        while(ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next;
            if(ptr_new_list->next != nullptr)
                ptr_new_list->next = ptr_new_list->next->next;
            else
                ptr_new_list->next = nullptr;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return result;
    }
};