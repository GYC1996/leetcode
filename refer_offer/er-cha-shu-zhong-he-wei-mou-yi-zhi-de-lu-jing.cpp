//输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
//从树的根节点开始往下一直到叶节点所经过的节点形成一条路径

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
    int count = 0;
    vector<int>s;
    vector<vector<int>>a;
    void dfs(TreeNode *root, int sum){
        if (root == NULL){
            return;
        }
        s.push_back(root -> val);
        count += root -> val;
        if (sum == count && root -> left == NULL && root -> right == NULL){ // meet needs
            a.push_back(s);
        }
        dfs(root -> left, sum);
        dfs(root -> right, sum);
        count -= s[s.size()-1];
        s.pop_back();
        // 如果使叶子节点，走完判断语句之后，再走 left right 的 dfs，然后pop掉自己 
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {   
        if (root == NULL){
            return {};
        }
        dfs(root, sum);
        return a;
    }
};
/*
这道题到叶子节点才能判断，因为不确定之后的元素是否有为负值的
所以如果提前终止可能会漏掉某些情况 
*/ 
