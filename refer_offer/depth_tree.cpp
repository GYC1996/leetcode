//����һ�ö������ĸ��ڵ㣬���������ȡ�
//�Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
//������������

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
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
            
        }
        int h1 = maxDepth(root -> left);
        int h2 = maxDepth(root -> right);
        int value = h1 > h2 ? h1 : h2;
        return value + 1;
    }
}; 
