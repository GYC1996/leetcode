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

//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int div = 1;
        int x = 0;
        int i = 0;
        for (i = 0; i < nums.size(); i++){
            x ^= nums[i]; // �����ɾ�����������ͬ���������
        }
        while ((div & x )== 0){
            div <<= 1; // ��div�������� ���� 1 2 4 8 16 ...
            // ֱ���Ƶ� ĳһλ Ϊ1��ʱ��ȷ����������ͬ��������һλ
        }
        // ͨ����һλ���з���
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
