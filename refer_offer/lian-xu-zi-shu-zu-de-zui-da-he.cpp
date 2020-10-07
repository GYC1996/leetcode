//����һ���������飬�����е�һ������������������һ�������顣������������ĺ͵����ֵ��
//
//Ҫ��ʱ�临�Ӷ�ΪO(n)��

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        int i = 0;
        for (i = 0; i < nums.size(); i++){
            if (sum <= 0){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            maxSum = maxSum > sum ? maxSum : sum;
        }
        return maxSum;
    }
};

/*
����˼·��
1.�������е����ֲ������ۼ�
2.���֮ǰ�ۼӵ�ֵС�ڻ����0����ȥ��֮ǰ�ı���������ӵ�ǰλ�ÿ�ʼ�ۼ�
3.���ǵ����ܶ��Ǹ�ֵ����������������̣�ÿ�ζ��Ὣ�ۼ�ֵ��ʼ��Ϊ��ǰֵ����˱����������ĸ��� 
*/ 

/*
�ɲ��ö�̬�滮���㷨 
*/ 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int maxSum = nums[0];
        for (i = 1; i < nums.size(); i++){
            if (nums[i-1] > 0){
                nums[i] += nums[i-1]; //��������ǰλ�õĺ͵Ĵ���0��ֵ 
            }
            maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
};

