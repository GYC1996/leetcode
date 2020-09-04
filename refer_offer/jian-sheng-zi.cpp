//����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����
//ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1] ������ k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣�
//���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��

/*
�ö�̬�滮���� 
*/ 
class Solution {
public:
    int max(int a, int b){
        if (a > b){
            return a;
        }
        else{
            return b;
        }
    }
    int cuttingRope(int n) {
        if (n == 2){
            return 1;
        }
        else if (n == 3){
            return 2;
        }
        else if (n == 4){
            return 4;
        }
        else{
            int i = 0, j=0, maxValue = 0;
            vector<int> dp(n+1, 0);
            dp[1] = 1;
            dp[2] = 1;
            dp[3] = 2;
            dp[4] = 4;
            for (i = 5; i <= n; i++){ // �ݹ���5��n�����ֵ
                maxValue = 0;
                for (j = 1; j <= i/2; j++){ // ÿ���������ֵ��
                    int temp = max(dp[i-j], i-j) * max(dp[j], j); //����ֱ�ӱ�֤�˷ָ���ڵ������εĸ���
																 //�����������ȥ�ָ��ֵ��С����ôֱ��ʹ�����ν������ 
																//��һ�������ʽ�� ����dp[0 1 2 3]Ϊ[0 1 2 3]��Ϊ�����ٷ�֮��û�б���Ĵ󣬴��Ŀ�ʼ��ָ� 
                    if (temp > maxValue){
                        maxValue = temp;
                    }
                }
                dp[i] = maxValue;
            }
            return dp[n];
        }
        return 0;
    }
};

/*
Ҳ��ֱ��ʹ��̰���㷨
�����ֳ�3�ĶΣ����ʣ��1�Ļ����ͷֳ�����2*2 
*/ 
class Solution {
public:
    int cuttingRope(int n) {
        // int length_3 = 0;
        if (n == 2){
            return 1;
        }
        else if (n == 3){
            return 2;
        }
        long value = 1;
        while (n > 4){
            value = value * 3;
            value = value % 1000000007;
            n = n - 3;
        }
        return (value * n) % 1000000007;
    }
};
