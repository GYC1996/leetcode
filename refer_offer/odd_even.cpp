//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

// 快速排序算法 简单版 
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
