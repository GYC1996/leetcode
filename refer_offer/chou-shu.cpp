//���ǰ�ֻ���������� 2��3 �� 5 ��������������Ugly Number����
//�󰴴�С�����˳��ĵ� n ������

//����: n = 10
//���: 12
//����: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 ��ǰ 10 ��������

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
����Ϊ��̬�滮����ʽ
 
*/ 


