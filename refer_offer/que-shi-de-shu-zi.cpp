//һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0��n-1֮�ڡ�
//�ڷ�Χ0��n-1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0;
        int end = nums.size();
        while (begin < end){
            int mid = (begin + end) / 2;
            if (nums[mid] == mid){
                begin = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return begin;
    }
};

/*
����ʹ����ֵ���ҷ��� 
�������end��Ϊ��׼�� nums.size()-1
 
*/ 
