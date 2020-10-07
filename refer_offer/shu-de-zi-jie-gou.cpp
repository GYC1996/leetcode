//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//
//B是A的子结构， 即 A中有出现和B相同的结构和节点值

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
    bool AhaveB(TreeNode *A, TreeNode *B){
        if (B == NULL){
            return true;
        } // B为空，不管 A 是否为空，确认 B为 A 的子树 
        if (A == NULL){
            return false;
        } // B 不为空，A 为空， 确认 B 不是 A 的子树 
        if (A->val != B->val){
            return false;
        }
        else
        	return AhaveB(A->left, B->left) && AhaveB(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;
        if (A == NULL || B == NULL){
            return false;
        }
        result = AhaveB(A, B);
        if (!result){
            result = isSubStructure(A->left, B);
        }
        if (!result){
            result = isSubStructure(A->right, B);
        }
        return result;
    } // 每个节点及其以下左子树 右子树都应该看成 A,然后再判断 A 是否包含 B 
};

/*
解题思路：
 
*/ 
