//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号

#include<iostream>
using namespace std;
int main(){
	int a = 5;
	int b = 6;
	while (b != 0){
		int c = (a & b) << 1; // 按位与操作 
		cout << c << " "; 
		a ^= b; // 按位异或操作 
		cout << a << " ";
		b = c;
		cout << b << " " << endl;
	}
	cout << a << endl;
	return a;
} 

// 5 6 为例
// 第一步求出 c 为 a 与 b 的按位与操作，然后再左移一位 ，相当于就是进位结果
// a 异或 b 求出为没进位的相加结果
// 指导没有进位的时候，退出循环，这时结果就是两者的异或操作 
