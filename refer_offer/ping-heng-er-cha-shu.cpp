//����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ���������
//���ĳ������������ڵ���������������������1����ô������һ��ƽ���������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int treehigh(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int h1 = treehigh(root -> left);
        int h2 = treehigh(root -> right);
        int value = h1 > h2 ? h1 : h2;
        return value + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        int h1 = treehigh(root -> left);
        int h2 = treehigh(root -> right);
        if (abs(h1 - h2) > 1){
            return false;
        }
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};

/*
ƽ���������������
1.�����������߲�С�ڵ��� 1��
2.����������Ϊƽ��������� 
*/

