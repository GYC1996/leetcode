//从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
//2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14

// 顺子的条件：除 0 外，所有的元素不可重复
//             除 0 外，所有的元素满足 max - min < 5

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // return false;
        unordered_map<int, int>mymap;
        int i = 0;
        int min = 14;
        int max = -1;
        for (i = 0; i < nums.size(); i++){
            mymap[nums[i]]++;
            if (nums[i] != 0){
                if (mymap[nums[i]] > 1){
                    return false; // 非零有重复直接退出 
                }
                if (nums[i] < min){
                    min = nums[i];
                }
                if (nums[i] > max){
                    max = nums[i];
                }
            }
        }
        if (mymap[0] == 5){
            return true;
        }
        return max-min<5; // 判断相距是否小于 5 
    }
}; 

