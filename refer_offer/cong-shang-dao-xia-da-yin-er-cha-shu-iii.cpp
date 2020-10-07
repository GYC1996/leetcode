#include<iostream>
#include<deque>
using namespace std;


int main(){
	deque<int>a;
	a.push_front(1);
	cout << a.front() <<endl;
//	a.push_back(0);
//	cout << a.back() << endl;
	a.push_front(3);
	cout << a.front() <<endl;
	cout << a.back() <<endl;
} 

// 双向队列其实和栈差不多 

//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
//第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
        if (root == NULL){
            return {};
        }
        deque<TreeNode *>dq;
        dq.push_front(root);
        bool sign = true;
        while (!dq.empty()){
            vector<int>list;
            TreeNode *temp;
            int size = dq.size();
            for (int i = 0; i < size; i++){
                if (sign){
                    temp = dq.back();
                    dq.pop_back();
                    list.push_back(temp -> val);
                    if (temp -> left != NULL){
                        dq.push_front(temp -> left);
                    }
                    if (temp -> right != NULL){
                        dq.push_front(temp -> right);
                    }
                }
                else{
                    temp = dq.front();
                    dq.pop_front();
                    list.push_back(temp -> val);
                    if (temp -> right != NULL){
                        dq.push_back(temp -> right);
                    }
                    if (temp -> left != NULL){
                        dq.push_back(temp -> left);
                    }
                }
            }
            sign = !sign;
            a.push_back(list);
        }
        return a;
    }
};

/* 
 具体思路
 使用双向队列
 使用back输出出来就使用front压进去，
 使用front输出出来就使用back压进去。
 实例：
 					20
			9				5
		10		1		8		2
	null null  7 6  null null  0 3
 	1.在主程序先将 20 用front压进去； 
 	2.while循环里使用back将 20 pop出来，然后使用先left后right的方式将 9 5 从front压进去，变成队列 5 9； 
 	3.将 5 9 从front pop出来，使用先right后left的方式将 2 8 1 10 从back端压进去，形成队列 2 8 1 10；
	4.将队列 2 8 1 10 从back端pop出来，输出 10 1 8 2，然后采用先left后right的方式，将 7 6 0 3 从front压进去，变成队列 3 0 6 7
	5. front端pop出 3 0 6 7 
*/ 
 
