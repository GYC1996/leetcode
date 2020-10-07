//��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�
//
//����Ҫ��һ�����������鷵�ش𰸣����е� i ��Ԫ�ش����� n ���������������ĵ��������е� i С���Ǹ��ĸ��ʡ�

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
ÿ�� dp[i][j] ������ dp[i-1][j-1] �� dp[i-1][j-6]ȷ���õ� 
*/ 

