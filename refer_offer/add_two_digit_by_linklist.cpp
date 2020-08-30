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
根据上面的思路能够计算出小数相加的结果，但是对于大数来说却不行
因此需要新的方法 
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
            int value = a[i] + b[i] + enter_bit; // 加法
            int current = value % 10;
            enter_bit = value / 10;
            node = new ListNode(current); // 新建的node
            if (i == 0){
                root = node;
            }
            else{
                pre -> next = node;
            }
            pre = node; // 将新建的node封装为pre
        }
        if (enter_bit != 0){
            node = new ListNode(enter_bit);
            pre -> next = node;
        }
        return root;
    }
};
/*
使用的方法
通过给出的两个链表，对每个数字分别进行相加
然后塞进链表输出
这样做的时间过长，需要重新进行优化
上面额代码相当于遍历了两遍 
如下 
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
优化流程如上
不需要使用额外的空间对提供的链表进行遍历存储
对链表遍历的过程中边计算值并存储 
*/ 
