//输入两个链表，找出它们的第一个公共节点。

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
headA 和 headB 长度不相等，但headA访问之后再访问headB到公共节点之前与headB访问之后再访问headA到公共节点之时走过的路径相等 
所以轮着访问总能找到公共节点 
*/
 
