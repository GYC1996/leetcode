//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其
//中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int>b(a.size(), 1);
        vector<int>c(a.size(), 1);
        int i = 1, j = 1;
        for (i = 1; i < a.size(); i++){
            b[i] = b[i-1] * a[i-1];
        }
        for (i = a.size()-2; i >= 0; i--){
            c[i] = c[i+1] * a[i+1];
        }
        for (i = 0; i < a.size(); i++){
            b[i] *= c[i];
        }
        return b;
    }
};

/*
通过上三角 下三角矩阵 相乘进行实现 
*/ 
