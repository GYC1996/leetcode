// �ǵݹ��������

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �ǵݹ��������
// ����ѹ ����ѹ Ȼ�󵯳� 
class Solution{
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int>a;
		stack<TreeNode*>s;
		s.push(root); // ���ڵ���ջ 
		while(!s.empty()){
			TreeNode *temp = s.top();
			s.pop();
			a.push_back(temp -> val);
			if (temp -> right) s.push(temp -> right);
			if (temp -> left) s.push(temp -> left);
		}
		return a;
	}
};

// �ǵݹ��������
// ��������ѹ����·����ջ���������ʣ�Ȼ��ѹ���ҽڵ� 
class Solution{
public:
	vector<int> inderTraversal(TreeNode* root){
		vector<int>a;
		stack<TreeNode*>s;
		TreeNode *temp = root; 
		while(temp || !s.empty()){
			while (temp){ // ��������ѹ 
				s.push(temp);
				temp = temp -> left;
			}
			temp = s.top(); //���� 
			s.pop();
			a.push_back(temp -> val); //ȡֵ 
			temp = temp -> right; // ������			
		}
		return a;
	}
}; 


//����һ�ö��������������ҳ����е�k��Ľڵ㡣
 
class Solution {
public:
    void traverse(TreeNode *root){
        if (root == NULL){
            return ;
        }
        traverse(root -> right);
        cout << root -> val << endl;
        traverse(root -> left);
    }
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL){
            return {};
        }

        traverse(root -> right);
        cout << root -> val << endl;
        traverse(root -> left);
        return 0;
    }
};
// ����Ϊ���õݹ�ķ��ʷ�ʽ
//���²��÷ǵݹ�ı�����ʽ
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
    int kthLargest(TreeNode* root, int k) {
        TreeNode *temp = root;
        stack<TreeNode*>s;
//        vector<int>a;
        int count = 0;
        while (temp || !s.empty()){
            while (temp){
                s.push(temp);
                temp = temp -> right;
            }
            temp = s.top();
            s.pop();
//            a.push_back(temp -> val);
            count++;
            if (count == k){ //��ʱ��ֹ 
                break;
            }
            temp = temp -> left;
        }
        return temp -> val;
    }
}; 


 
