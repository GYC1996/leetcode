//输入一个递增排序的数组和一个数字s，在数组中查找两个数，
//使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin <= end){
            if (nums[begin] + nums[end] > target){
                end = end -1;
            }
            else if (nums[begin] + nums[end] < target){
                begin = begin + 1;
            }
            else{
                break;
            }
        }
        vector<int>a(2, 0);
        a[0] = nums[begin];
        a[1] = nums[end];
        return a;
    }
};

/*
双指针，一个指向头，另一个指向尾部
相加小于target，头指针向后移动；
相加大于target，尾指针向前移动；
相等时直接输出 
*/ 


