/*输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
思路：
可遍历数组，然后利用vector前面进行插入 
vector前向的插入方法 a.insert(a.begin(), head -> val); 
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
// 使用该方法耗时长
// 如下使用栈进行操作
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
 
