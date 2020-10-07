//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
//如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

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
平衡二叉树的条件：
1.左右子树树高差小于等于 1；
2.左右子树均为平衡二叉树； 
*/

