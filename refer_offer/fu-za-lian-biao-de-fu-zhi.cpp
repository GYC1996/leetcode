//map： map内部实现了一个红黑树，红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素 
//unordered_map: unordered_map内部实现了一个哈希表，其元素的排列顺序是无序的 

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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *>my_map;
        Node *t = head;
        while (t != NULL){
            my_map[t] = new Node(t -> val); // 初始化新节点
            // 键值对的键为原来的指针地址；值为新节点的地址
            t = t -> next;
        }
        t = head;
        while (t != NULL){
            my_map[t] -> next = my_map[t->next];
            // 值指向的下一个节点为 
            my_map[t] -> random = my_map[t->random];
            t = t -> next;
        }
        return my_map[head];
    }
};
// 主要是创建了一个字典/哈希表
// 键存放原来的地址，值存放现在的地址
// 第二个whle循环中：
// 当前值指向next为下一个值的地址； 



