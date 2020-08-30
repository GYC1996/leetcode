/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i = 0;
        int value1 = 0, value2 = 0;
        while (l1 != NULL){
            value1 += l1 -> val * pow(10, i);
            i++;
            l1 = l1 -> next;
        }
        i = 0;
        while (l2 != NULL){
            value2 += l2 -> val * pow(10, i);
            i++;
            l2 = l2 -> next;
        }
        cout << value1 << " " << value2 <<endl;
        // return 0;
        int value = value1 + value2;
        ListNode *root;
        int val = value % 10;
        value = value / 10;
        root = new ListNode(val);
        ListNode *list = root;  
        while (value != 0){ 
            val = value % 10;
            value = value / 10;
            ListNode *temp = new ListNode(val);
            list -> next = temp;
            list = temp;
        }
        return root;
    }
};
/*
���������˼·�ܹ������С����ӵĽ�������Ƕ��ڴ�����˵ȴ����
�����Ҫ�µķ��� 
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>a, b;
        while (l1 != NULL){
            a.push_back(l1->val);
            l1 = l1 -> next;
        }
        while (l2 != NULL){
            b.push_back(l2 -> val);
            l2 = l2 -> next;
        }
        if (a.size() < b.size()){
            int diff = b.size() - a.size();
            for (int i = 0; i < diff; i++){
                a.push_back(0);
            }
        }
        else if (a.size() > b.size()){
            int diff = a.size() - b.size();
            for (int i = 0; i < diff; i++){
                b.push_back(0);
            }
        }
        // ListNode *root = new ListNode()
        ListNode *pre, *root, *node;
        int enter_bit = 0;
        for (int i = 0; i < a.size(); i++){
            int value = a[i] + b[i] + enter_bit; // �ӷ�
            int current = value % 10;
            enter_bit = value / 10;
            node = new ListNode(current); // �½���node
            if (i == 0){
                root = node;
            }
            else{
                pre -> next = node;
            }
            pre = node; // ���½���node��װΪpre
        }
        if (enter_bit != 0){
            node = new ListNode(enter_bit);
            pre -> next = node;
        }
        return root;
    }
};
/*
ʹ�õķ���
ͨ������������������ÿ�����ֱַ�������
Ȼ�������������
��������ʱ���������Ҫ���½����Ż�
���������൱�ڱ��������� 
���� 
*/ 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1, val2, value, enter_bit = 0, i = 0, current = 0;
        ListNode *root, *node, *pre;
        while (l1 != NULL || l2 != NULL){
            if (l1 != NULL){
                val1 = l1 -> val;
                l1 = l1 -> next; 
            }
            else{
                val1 = 0;
            }
            if (l2 != NULL){
                val2 = l2 -> val;
                l2 = l2 -> next;
            }
            else{
                val2 = 0;
            }
            value = val1 + val2 + enter_bit;
            current = value % 10;
            enter_bit = value / 10;
            node = new ListNode(current);
            if (i == 0){
                root = node;
            }
            else{
                pre -> next = node;
            }
            pre = node;
            i++; 
        }
        if (enter_bit != 0){
            node = new ListNode(enter_bit);
            pre -> next = node;
        }
        return root;
    }
};
/*
�Ż���������
����Ҫʹ�ö���Ŀռ���ṩ��������б����洢
����������Ĺ����б߼���ֵ���洢 
*/ 
