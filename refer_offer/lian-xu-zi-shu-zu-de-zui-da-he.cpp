//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
//
//要求时间复杂度为O(n)。

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
具体思路：
1.遍历所有的数字并进行累加
2.如果之前累加的值小于或等于0，则去除之前的遍历结果，从当前位置开始累加
3.考虑到可能都是负值，如果依上述的流程，每次都会将累计值初始化为当前值，因此保留的是最大的负数 
*/ 

/*
可采用动态规划的算法 
*/ 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int maxSum = nums[0];
        for (i = 1; i < nums.size(); i++){
            if (nums[i-1] > 0){
                nums[i] += nums[i-1]; //保留到当前位置的和的大于0的值 
            }
            maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
};

