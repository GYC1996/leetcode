//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

// ���������㷨 �򵥰� 
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() == 0){
            return nums;
        }
        int i = 0, j = nums.size() - 1;
        while (true){
            while (i < j && nums[i] % 2 != 0){
                i++;
            }
            while (i < j && nums[j] % 2 == 0){
                j--;
            }
            if (i < j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            else{
                break;
            }
        }
        return nums;
    }
};
