//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字

// 使用递归的方法进行构建二叉树

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
                break; // 找到子树root的位置
            }
        }
        // cout << i <<endl;
        root -> left = binaryTree(preorder, inorder, pre_start+1, pre_start+i-in_start, in_start, i-1);
        root -> right = binaryTree(preorder, inorder, pre_end-(in_end-i)+1, pre_end, i+1, in_end);
        return root;
    }
};

/*
具体思路：
使用递归的方法
根据中序遍历把每个节点分为 左子树 右子树 
传进去先序遍历和中序遍历

左子树： 
先序遍历的起点：当前先序遍历的位置+1 
先序遍历的终点：由中序遍历位置得到中序遍历左子树的节点的个数，再加上先序遍历的位置 
中序遍历的起点：中序遍历的起点 
中序遍历的终点：中序中点的值-1 

右子树：
先序遍历的起点：由中序遍历可得到中序遍历右子树的个数，根据先序遍历的终点可得到先序遍历的起点 
先序遍历的终点：先序遍历的终点 
中序遍历的起点：中序的中点+1 
中序遍历的终点：中序的终点 
*/ 
