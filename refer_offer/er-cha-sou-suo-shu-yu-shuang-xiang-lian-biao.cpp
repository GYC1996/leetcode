//����һ�ö��������������ö���������ת����һ�������ѭ��˫������
//Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

//�������������������ӽڵ�תΪǰ������ڵ�

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
        // ����Ϊ�������
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

// ʹ��һ��ջ����ԭʼ������������� 
// ʹ��һ��vector�����нڵ����
// ������ʱ��Ϊ 2n
// ���³����� n ��ʱ�临�Ӷ����������ٶȺͿռ临�Ӷȶ��õ��ϴ������ 

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL){
            return NULL;
        }
        stack<Node *>s;
        Node *t = root;
        // ����Ϊ�������
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
                cur = t; //��¼��ǰ�ڵ�
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
