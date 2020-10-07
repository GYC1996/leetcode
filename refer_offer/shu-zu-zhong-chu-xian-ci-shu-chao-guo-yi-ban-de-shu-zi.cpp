// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, current = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (current != nums[i]){
                count--;
                if (count < 0){
                    current = nums[i];
                    count = 1;
                }
            }
            else{
                count++;
            }
        }
        return current;
    }
}; 

// 解题思路
// 因为有一个数字出现的次数大于数组一半的长度
// 用除它本身之外的任何一个数字对它进行削去，还是会有剩余
//  
