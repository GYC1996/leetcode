//map�� map�ڲ�ʵ����һ�������������������Զ�����Ĺ��ܣ����map�ڲ�������Ԫ�ض�������ģ��������ÿһ���ڵ㶼������map��һ��Ԫ�� 
//unordered_map: unordered_map�ڲ�ʵ����һ����ϣ����Ԫ�ص�����˳��������� 

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
            my_map[t] = new Node(t -> val); // ��ʼ���½ڵ�
            // ��ֵ�Եļ�Ϊԭ����ָ���ַ��ֵΪ�½ڵ�ĵ�ַ
            t = t -> next;
        }
        t = head;
        while (t != NULL){
            my_map[t] -> next = my_map[t->next];
            // ֵָ�����һ���ڵ�Ϊ 
            my_map[t] -> random = my_map[t->random];
            t = t -> next;
        }
        return my_map[head];
    }
};
// ��Ҫ�Ǵ�����һ���ֵ�/��ϣ��
// �����ԭ���ĵ�ַ��ֵ������ڵĵ�ַ
// �ڶ���whleѭ���У�
// ��ǰֵָ��nextΪ��һ��ֵ�ĵ�ַ�� 



