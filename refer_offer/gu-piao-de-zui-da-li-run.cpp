//假设把某股票的价格按照时间先后顺序存储在数组中，
//请问买卖该股票一次可能获得的最大利润是多少

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
先求 两天之间的差值
再转化为 “连续子数组的最大和”来求解 
*/ 

// 快速乘法实现
int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
    	// 对 B 进行右移
		// 假设对 B 右移 i 位
		// 那就是 A * （B / i）
		// 相当于 A << i 
        if (B & 1) {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}


