//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3, *node;
        if (l1 == NULL){
            return l2;
        }
        else if (l2 == NULL){
            return l1; 
        }
        if (l1 -> val > l2 -> val){
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
        else{
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
    }
};
/*
采用递归的方法，
每次选择 较小的数进行连接 

*/ 
