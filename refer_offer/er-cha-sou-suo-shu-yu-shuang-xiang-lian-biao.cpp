//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
//要求不能创建任何新的节点，只能调整树中节点指针的指向

//将二叉搜索树的左右子节点转为前驱后序节点

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL){
            return NULL;
        }
        vector<Node *>v;
        stack<Node *>s;
        Node *t = root;
        // 以下为中序遍历
        while (!s.empty() || t != NULL){
            while (t != NULL){
                s.push(t);
                t = t -> left;
            }
            t = s.top();
            v.push_back(t);
            s.pop();
            cout << t -> val << " ";
            t = t -> right;
        }
        Node *head = v[0];
        int i = 0;
        for (i = 0; i < v.size() - 1; i++){
            v[i] -> right = v[i+1];
            v[i+1] -> left = v[i];
        }
        v[i] -> right = v[0];
        v[0] -> left = v[i];
        return head;
        // return root;
    }
};

// 使用一个栈来对原始树进行中序遍历 
// 使用一个vector来进行节点操作
// 遍历的时间为 2n
// 以下尝试用 n 的时间复杂度来操作，速度和空间复杂度都得到较大的提升 

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL){
            return NULL;
        }
        stack<Node *>s;
        Node *t = root;
        // 以下为中序遍历
        Node *pre = NULL, *cur = NULL, *head = NULL;
        while (!s.empty() || t != NULL){
            while (t != NULL){
                s.push(t);
                t = t -> left;
            }
            t = s.top();
            if (head == NULL){
                head = t;
                cur = t;
            }
            else{
                pre = cur;
                cur = t; //记录当前节点
                pre -> right = cur;
                cur -> left = pre;
            }
            s.pop();
            cout << t -> val << " ";
            t = t -> right;
        }
        cur -> right = head;
        head -> left = cur;
        return head;
    }
}; 
