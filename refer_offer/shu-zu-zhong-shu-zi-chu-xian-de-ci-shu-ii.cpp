//��һ������ nums �г�һ������ֻ����һ��֮�⣬
//�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε�����

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int i = 0;
//        // long div = 1;
//        int j = 0;
//        int ans = 0;
//        for (i = 0; i < 32; i++){ // ���� i λ
//            int cnt = 0;
//            for (j = 0; j < nums.size(); j++){
//                // cnt += (((1 << i)) & nums[j]); // ͳ��ÿ��������֮��
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
	cout << ((1 << 2) & 4) << endl; // ���4 ���� 1 
	return 0;
} 

