// 非递归中序遍历

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

// 非递归先序遍历
// 往右压 往左压 然后弹出 
class Solution{
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int>a;
		stack<TreeNode*>s;
		s.push(root); // 根节点入栈 
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

// 非递归中序遍历
// 不断往左压，沿路径入栈，弹出访问，然后压入右节点 
class Solution{
public:
	vector<int> inderTraversal(TreeNode* root){
		vector<int>a;
		stack<TreeNode*>s;
		TreeNode *temp = root; 
		while(temp || !s.empty()){
			while (temp){ // 不断往左压 
				s.push(temp);
				temp = temp -> left;
			}
			temp = s.top(); //弹出 
			s.pop();
			a.push_back(temp -> val); //取值 
			temp = temp -> right; // 往右走			
		}
		return a;
	}
}; 


//给定一棵二叉搜索树，请找出其中第k大的节点。
 
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
// 如上为采用递归的访问方式
//如下采用非递归的遍历方式
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
            if (count == k){ //及时终止 
                break;
            }
            temp = temp -> left;
        }
        return temp -> val;
    }
}; 


 
