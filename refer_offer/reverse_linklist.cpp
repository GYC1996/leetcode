/*����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
˼·��
�ɱ������飬Ȼ������vectorǰ����в��� 
vectorǰ��Ĳ��뷽�� a.insert(a.begin(), head -> val); 
*/

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
    vector<int> reversePrint(ListNode* head) {
        vector<int>a;
        while (head != NULL){
            a.insert(a.begin(), head -> val);
            head = head -> next;
        }
        return a;
    }
};
// ʹ�ø÷�����ʱ��
// ����ʹ��ջ���в���
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
    vector<int> reversePrint(ListNode* head) {
        // vector<int>a;
        stack<int>a;
        vector<int>b;
        while (head != NULL){
            // a.insert(a.begin(), head -> val);
            a.push (head->val);
            head = head -> next;
        }
        while (!a.empty()){
            b.push_back(a.top());
            a.pop();
        }
        return b;
    }
}; 
 
