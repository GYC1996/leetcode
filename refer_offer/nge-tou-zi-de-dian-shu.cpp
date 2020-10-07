//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//
//你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>>dp(n+1, vector<int>(6*n+1, 0));
        int i = 0, j = 0;
        for (i = 1; i <= 6; i++){
            dp[1][i] = 1;
        }
        for (i = 2; i <= n; i++){
            for (j = i; j <= i*6; j++){
                for (int k = j-1; k >= j-6; k--){
                    if (k < 1){
                        break;
                    }
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        vector<double>a;
        int all = pow(6, n);
        for (i = n; i <= n*6; i++){
            a.push_back(dp[n][i] * 1.0 / all);
        }
        return a;
    }
};

/*
每个 dp[i][j] 均可由 dp[i-1][j-1] 到 dp[i-1][j-6]确定得到 
*/ 

