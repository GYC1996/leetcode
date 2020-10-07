//�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У�
//���������ù�Ʊһ�ο��ܻ�õ���������Ƕ���

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1){
            return 0;
        }
        int i = 1;
        vector<int>diff;
        for (i = 1; i < n; i++){
            diff.push_back(prices[i]-prices[i-1]);
        }
        int max = 0;
        int sum = 0;
        for (i = 0; i < diff.size(); i++){
            if (sum <= 0){
                sum = diff[i];
            }
            else{
                sum += diff[i];
            }
            max = max > sum ? max : sum;
        }
        return max;
    }
};

/*
���� ����֮��Ĳ�ֵ
��ת��Ϊ ����������������͡������ 
*/ 

// ���ٳ˷�ʵ��
int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
    	// �� B ��������
		// ����� B ���� i λ
		// �Ǿ��� A * ��B / i��
		// �൱�� A << i 
        if (B & 1) {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}


