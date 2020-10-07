//�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)
//
//B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ

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
        } // BΪ�գ����� A �Ƿ�Ϊ�գ�ȷ�� BΪ A ������ 
        if (A == NULL){
            return false;
        } // B ��Ϊ�գ�A Ϊ�գ� ȷ�� B ���� A ������ 
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
    } // ÿ���ڵ㼰������������ ��������Ӧ�ÿ��� A,Ȼ�����ж� A �Ƿ���� B 
};

/*
����˼·��
 
*/ 
