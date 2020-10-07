#include<iostream>
//using namespace std; 
//
//int main(){
//	int div = 1;
//	int n = 0;
//	while (n <= 10){
//		div <<= 1;
//		cout << div << endl;
//		n++; 
//	}
//}

//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int div = 1;
        int x = 0;
        int i = 0;
        for (i = 0; i < nums.size(); i++){
            x ^= nums[i]; // 异或完成就是两个不相同数的异或结果
        }
        while ((div & x )== 0){
            div <<= 1; // 对div进行左移 可能 1 2 4 8 16 ...
            // 直到移到 某一位 为1的时候，确认两个不相同的数的那一位
        }
        // 通过这一位进行分组
        int a = 0, b = 0;
        for (i = 0; i < nums.size(); i++){
            if (nums[i] & div){
                a ^= nums[i];
            }
            else{
                b ^= nums[i];
            }
        }
        return vector<int>{a, b};
    }
};
