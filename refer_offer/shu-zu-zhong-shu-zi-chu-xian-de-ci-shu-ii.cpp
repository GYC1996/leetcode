//在一个数组 nums 中除一个数字只出现一次之外，
//其他数字都出现了三次。请找出那个只出现一次的数字

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int i = 0;
//        // long div = 1;
//        int j = 0;
//        int ans = 0;
//        for (i = 0; i < 32; i++){ // 左移 i 位
//            int cnt = 0;
//            for (j = 0; j < nums.size(); j++){
//                // cnt += (((1 << i)) & nums[j]); // 统计每个数左移之后
//                if (((1 << i)) & nums[j]){
//                    cnt++;
//                }
//            }
//            // div = (div << 1);
//            if (cnt % 3 == 1){
//                ans ^= (1 << i);
//            }
//        }
//        return ans;
//    }
//};

#include<iostream>
using namespace std;
int main(){
	cout << ((1 << 2) & 4) << endl; // 输出4 并非 1 
	return 0;
} 

