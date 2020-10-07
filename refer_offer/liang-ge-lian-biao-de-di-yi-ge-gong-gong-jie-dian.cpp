//�������������ҳ����ǵĵ�һ�������ڵ㡣

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return 0
        // return headA;
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        while (node1 != node2){
            node1 = node1 != NULL ? node1 -> next : headB;
            node2 = node2 != NULL ? node2 -> next : headA;
        }
        return node1;
    }
};

/*
headA �� headB ���Ȳ���ȣ���headA����֮���ٷ���headB�������ڵ�֮ǰ��headB����֮���ٷ���headA�������ڵ�֮ʱ�߹���·����� 
�������ŷ��������ҵ������ڵ� 
*/
 
