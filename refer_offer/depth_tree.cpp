//输入一棵二叉树的根节点，求该树的深度。
//从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
//二叉树求树高

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
