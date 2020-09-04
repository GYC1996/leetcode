//����ĳ��������ǰ���������������Ľ�������ؽ��ö�������
//���������ǰ���������������Ľ���ж������ظ�������

// ʹ�õݹ�ķ������й���������

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_start = 0, in_start = 0;
        int pre_end = preorder.size() - 1, in_end = inorder.size() - 1;
        return binaryTree(preorder, inorder, pre_start, pre_end, in_start, in_end);
    }
    
    TreeNode* binaryTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end){
        if(pre_start > pre_end || in_start > in_end) return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int i;
        for (i = in_start; i <= in_end; i++){
            if (inorder[i] == preorder[pre_start]){
                break; // �ҵ�����root��λ��
            }
        }
        // cout << i <<endl;
        root -> left = binaryTree(preorder, inorder, pre_start+1, pre_start+i-in_start, in_start, i-1);
        root -> right = binaryTree(preorder, inorder, pre_end-(in_end-i)+1, pre_end, i+1, in_end);
        return root;
    }
};

/*
����˼·��
ʹ�õݹ�ķ���
�������������ÿ���ڵ��Ϊ ������ ������ 
����ȥ����������������

�������� 
�����������㣺��ǰ���������λ��+1 
����������յ㣺���������λ�õõ���������������Ľڵ�ĸ������ټ������������λ�� 
�����������㣺������������ 
����������յ㣺�����е��ֵ-1 

��������
�����������㣺����������ɵõ���������������ĸ�������������������յ�ɵõ������������� 
����������յ㣺����������յ� 
�����������㣺������е�+1 
����������յ㣺������յ� 
*/ 
