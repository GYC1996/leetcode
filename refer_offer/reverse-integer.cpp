//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

//这道题不需要开辟额外的队列空间来存储每一位数字

class Solution {
public:
    int reverse(int x) {
        long sum = 0;
        while (x != 0){
            int temp = x % 10;
            sum = sum * 10 + temp;
            x = x / 10;
        }
        if (sum >= INT_MAX || sum <= INT_MIN)
            sum = 0;
        return sum;
    }
}; 

// -123 % 10 =  -3    123 / 10 = -12
 

