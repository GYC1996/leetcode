//��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ������ô���ǶԳƵġ�


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
    bool isequal(TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL){
            return true;
        }
        else if (left == NULL || right == NULL){
            return false;
        }
        else if (left -> val != right -> val){
            return false;
        }
        else{
            return isequal(left -> right, right -> left) && isequal(left -> left, right -> right);
        }
    }
    bool isSymmetric(TreeNode* root) {
        // branch1, *branch2;
        if (root == NULL){
            return true;
        }
        else{
            return isequal(root -> left, root -> right);
        }
    }
};

// ʹ�õݹ�ķ��� 
