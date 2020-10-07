//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
//求按从小到大的顺序的第 n 个丑数

//输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int i = 0;
        vector<int>dp(n, 0);
        dp[0] = 1;
        for (i = 1; i < n; i++){
            dp[i] = min(dp[a]*2, min(dp[b]*3, dp[c]*5));
            if (dp[i] == dp[a]*2) a++;
            if (dp[i] == dp[b]*3) b++;
            if (dp[i] == dp[c]*5) c++;
        }
        return dp[n-1];
    }
};

/*
dp[i] = min(dp[a]*2, min(dp[b]*3, dp[c]*5)); 
如上为动态规划方程式
 
*/ 


