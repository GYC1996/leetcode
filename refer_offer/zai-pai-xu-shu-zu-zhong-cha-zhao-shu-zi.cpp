//统计一个数字在排序数组中出现的次数。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return 0;
        }
        int begin = 0, end = nums.size() - 1;
        int mid = 0;
        int count = 0;
        while (begin <= end){
            mid = (begin + end) / 2;
            if (nums[mid] > target){
                end = mid - 1;
            }
            else if (nums[mid] < target){
                begin = mid + 1;
            }
            else{
                for (int i = mid; i >= begin; i--){
                    if (nums[i] == target){
                        count++;
                    }
                }
                for (int i = mid + 1; i <= end; i++){
                    if (nums[i] == target){
                        count++;
                    }                    
                }
                break;
            }
        }
        return count;
    }
};

/*
中值查找方法 
*/ 

