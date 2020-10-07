#include<iostream>
using namespace std;
int main(){
	int exp = 9;
	int x = 5;
	while (exp){
		if (exp & 1){
			cout << "1" << endl;
		}
		else{
			cout << "0" << endl;
		}
		exp >>= 1;
		cout << "exp = " << exp << endl;
	}
}

//实现函数double Power(double base, int exponent)，求base的exponent次方。
//不得使用库函数，同时不需要考虑大数问题。

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1){
            return 1;
        }
        if (x == 0){
            return 0;
        }
        long exp = n;
        double res = 1.0;
        if (n < 0){
            x = 1 / x;
            exp = -exp;
        }
        while (exp){
            if (exp & 1){
                res *= x;
            }
            x *= x;
            exp >>= 1;
        }
        return res;
    }
};

/*
具体思路：
如果 n<0, 把 n 取负，x取为 i 原来的倒数 
将 n 与末位数进行与操作，如果是 1 就进行相乘
将 乘数变为原来的两倍，因为进行了移位操作 
*/

