//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
//每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
//例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

/*
用动态规划来做 
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
            for (i = 5; i <= n; i++){ // 递归求5到n的最大值
                maxValue = 0;
                for (j = 1; j <= i/2; j++){ // 每个数的最大值求法
                    int temp = max(dp[i-j], i-j) * max(dp[j], j); //这里直接保证了分割大于等于两段的个数
																 //如果两段再下去分割的值更小，那么直接使用两段进行相乘 
																//另一种替代方式是 定义dp[0 1 2 3]为[0 1 2 3]因为他们再分之后没有本身的大，从四开始求分割 
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
也可直接使用贪心算法
尽量分成3的段，如果剩余1的话，就分成两个2*2 
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
