//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。


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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        vector<int>a;
        if (root == NULL){
            return {};
        }
        q.push(root);
        // a.push_back(root -> val);
        while (!q.empty()){
            TreeNode *temp = q.front(); // first
            if (temp -> left != NULL){
                q.push(temp -> left);
            }
            if (temp -> right != NULL){
                q.push(temp -> right);
            }
            a.push_back(temp -> val);
            q.pop();
        }
        return a;
    }
};

/*
队列实现的层次遍历 
*/ 
