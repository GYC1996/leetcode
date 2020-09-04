//写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
//
//F(0) = 0,? ?F(1)?= 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
//斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
//
//答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

class Solution {
public:
    int fib(int n) {
        if (n == 0){
            return 0;
        }
        else if (n == 1){
            return 1;
        }
        else{
            unsigned int fn1 = 0, fn2 = 1;
            unsigned int i, fn;
            for (i = 2; i <= n; i++){
                fn = (fn1 + fn2) % 1000000007;
                fn1 = fn2;
                fn2 = fn;
            }
            return fn % 1000000007;
        }
    }
};

/*
这样做是用时间换空间，空间消耗很少，但多了两个赋值操作
时间开销就会比较大
但是发现如果把unsigned去掉之后就ok了 
*/


