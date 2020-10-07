//请完成一个函数，输入一个二叉树，该函数输出它的镜像
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL){
            return NULL;
        }
        swap(root -> left, root -> right);
        // TreeNode *temp = root -> left;
        // root -> left = root -> right;
        // root -> right = temp;
        mirrorTree(root -> left);
        mirrorTree(root -> right);
        return root;
    }
};
