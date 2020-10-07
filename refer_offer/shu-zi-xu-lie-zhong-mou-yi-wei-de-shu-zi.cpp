//数字以0123456789101112131415…的格式序列化到一个字符序列中。
//在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等

class Solution {
public:
    int findNthDigit(int n) {
    	long m = n; 
        if (m == 0){
            return 0;
        }
        int bit = 1;
        while (m > 0){
            m = m - 9 * pow(10, bit-1) * bit;
            bit += 1;
        }
        bit -= 1;
        m += 9 * pow(10, bit-1) * bit; //这里求的是 bit 位数字的第 m 个数字 
        m = m - 1; // m-1主要是为了满足0位而不是1位 
        //这是输出bit位数的第n个位置 比如输入n=9 此时n=9， bit=1
        long num = pow(10, bit-1) + m / bit; //这是输出哪个数，比如9
        int b = m % bit; // num的第b位
        cout << num << " " << bit << " " << b << ' ' << n << endl;
        return (num / int(pow(10, bit-b-1))) % 10;
    }
};
