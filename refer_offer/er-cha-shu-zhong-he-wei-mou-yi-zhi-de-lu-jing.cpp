//����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
//�����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·��

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
        // ���ʹҶ�ӽڵ㣬�����ж����֮������ left right �� dfs��Ȼ��pop���Լ� 
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
����⵽Ҷ�ӽڵ�����жϣ���Ϊ��ȷ��֮���Ԫ���Ƿ���Ϊ��ֵ��
���������ǰ��ֹ���ܻ�©��ĳЩ��� 
*/ 
