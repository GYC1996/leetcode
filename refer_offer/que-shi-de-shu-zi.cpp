//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
//在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。


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
这里使用中值查找方法 
但这里的end不为标准的 nums.size()-1
 
*/ 
