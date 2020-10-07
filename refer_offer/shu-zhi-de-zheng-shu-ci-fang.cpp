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

//ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η���
//����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

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
����˼·��
��� n<0, �� n ȡ����xȡΪ i ԭ���ĵ��� 
�� n ��ĩλ������������������ 1 �ͽ������
�� ������Ϊԭ������������Ϊ��������λ���� 
*/

