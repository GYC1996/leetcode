//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>a;
        vector<int> list;
        queue<TreeNode *>q;
        queue<int>index;
        if (root == NULL){
            return {};
        }
        q.push(root);
        index.push(1);
        int pre_index = 1;
        while (!q.empty()){
            TreeNode *temp = q.front();
            int rank = index.front();
            if (rank != pre_index){
                a.push_back(list);
                list.clear();
                pre_index = rank;
            }// 当rank发生变化时，将之前所有地值push进去二维数组，然后进行清空 
            if (temp -> left != NULL){
                q.push(temp -> left);
                index.push(rank + 1);
            }
            if (temp -> right != NULL){
                q.push(temp -> right);
                index.push(rank + 1);
            }
            list.push_back(temp -> val);
            q.pop();
            index.pop();
        }
        a.push_back(list);
        return a;  
    }
};
/*
如上地思路是使用另一个队列来存储当前为第几层 
以下为另一种解法，即使用遍历当前层的个数，这样的方法花费较少的时间 
*/ 

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        vector<vector<int>>a;
        if (root == NULL){
            return {};
        }
        q.push(root);
        while (!q.empty()){
            int current_nodes = q.size(); // 计算当前的节点个数 
            vector<int>current;
            for (int i = 0; i < current_nodes; i++){
                TreeNode *temp = q.front(); // for循环正好遍历一层 
                current.push_back(temp -> val);
                q.pop();
                if (temp -> left != NULL){
                    q.push(temp -> left);
                }
                if (temp -> right != NULL){
                    q.push(temp -> right);
                }
            }
            a.push_back(current);
        }
        return a;
    }
};
