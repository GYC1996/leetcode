//���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�

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
            }// ��rank�����仯ʱ����֮ǰ���е�ֵpush��ȥ��ά���飬Ȼ�������� 
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
���ϵ�˼·��ʹ����һ���������洢��ǰΪ�ڼ��� 
����Ϊ��һ�ֽⷨ����ʹ�ñ�����ǰ��ĸ����������ķ������ѽ��ٵ�ʱ�� 
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
            int current_nodes = q.size(); // ���㵱ǰ�Ľڵ���� 
            vector<int>current;
            for (int i = 0; i < current_nodes; i++){
                TreeNode *temp = q.front(); // forѭ�����ñ���һ�� 
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
