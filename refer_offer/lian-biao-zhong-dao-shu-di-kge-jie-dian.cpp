//����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
//�����1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������6���ڵ㣬
//��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6��
//�������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣

/*
����pre�ڵ��ڵ�ǰ�ڵ��ǰ��λ 
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pre = head;
        while (k > 0){
            head = head -> next;
            k--;
        }
        while (head != NULL){
            head = head -> next;
            pre = pre -> next;
        }
        return pre;
    }
};

