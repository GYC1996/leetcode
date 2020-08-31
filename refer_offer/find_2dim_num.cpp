//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
//ʾ��:
//
//���о��� matrix ���£�
//
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
//
//���� target = 5������ true��
//
//���� target = 20������ false��

/*
����˼·��
һ��ʼ���ϵ��´��������α����������ֲ���
���뽫���ҹ���ת��Ϊ���������ң������½ǿ�ʼ������Ͻǿ�ʼ����
                		15
		    	11  			19
			7			12				22
		4		8				16				24
	1		5			9				17				30 
		 
*/ 
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        
        // cout << matrix.size()<<" "<<matrix[0].size()<<endl;
        // for (i = 0; i < )
        // cout << matrix.empty() <<endl;
        if (matrix.empty() || matrix[0].empty()){
            return false;
        }
        int i = 0, j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0){
            if (matrix[i][j] == target){
                return true;
            }
            else if (matrix[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};

/*
������Ҫ�ж������Ƿ�Ϊ�� 
matrix.empty() || matrix[0].empty()
*/ 
 
