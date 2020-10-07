//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

class Solution {
public:
    bool isPalindrome(int x) {
        // deque<int>q;
        if (x < 0){
            return false;
        }
        if (x % 10 == 0 && x != 0){
            return false;
        }
        int sum = 0;
        while (x > sum){
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (x == sum || x == sum / 10);
    }
};

// 思路：
// 1.负数以及末位为 0 的数一定不是回文数
// 2.将整个数字除到一半以上，通过对比结果得到
// 3.奇数就再除以一位 偶数直接判断 
 

