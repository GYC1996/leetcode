//����һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return head;
        }
        else{
            ListNode *post, *head2;
            post = new ListNode(head -> val);
            head2 = post;
            head = head -> next;
            while (head != NULL){
                head2 = new ListNode(head -> val);
                head2 -> next = post;
                post = head2;
                head = head -> next;
            }
            return head2;
        }
    }
};
