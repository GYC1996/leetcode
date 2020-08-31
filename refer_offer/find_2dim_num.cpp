//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//示例:
//
//现有矩阵 matrix 如下：
//
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
//
//给定 target = 5，返回 true。
//
//给定 target = 20，返回 false。

/*
解题思路：
一开始从上到下从左到右依次遍历，但发现不行
必须将查找过程转变为二叉树查找，从左下角开始或从右上角开始查找
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
并且需要判断数组是否为空 
matrix.empty() || matrix[0].empty()
*/ 
 
