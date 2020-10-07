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

// ˫�������ʵ��ջ��� 

//��ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳���ӡ��
//�ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ���������Դ����ơ�

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
 ����˼·
 ʹ��˫�����
 ʹ��back���������ʹ��frontѹ��ȥ��
 ʹ��front���������ʹ��backѹ��ȥ��
 ʵ����
 					20
			9				5
		10		1		8		2
	null null  7 6  null null  0 3
 	1.���������Ƚ� 20 ��frontѹ��ȥ�� 
 	2.whileѭ����ʹ��back�� 20 pop������Ȼ��ʹ����left��right�ķ�ʽ�� 9 5 ��frontѹ��ȥ����ɶ��� 5 9�� 
 	3.�� 5 9 ��front pop������ʹ����right��left�ķ�ʽ�� 2 8 1 10 ��back��ѹ��ȥ���γɶ��� 2 8 1 10��
	4.������ 2 8 1 10 ��back��pop��������� 10 1 8 2��Ȼ�������left��right�ķ�ʽ���� 7 6 0 3 ��frontѹ��ȥ����ɶ��� 3 0 6 7
	5. front��pop�� 3 0 6 7 
*/ 
 
