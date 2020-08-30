class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int a[100000] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            if (a[nums[i]] == 1)
            {
                return nums[i];
            }
            else
            {
                a[nums[i]] = 1;
            }
        }
        return 0;
    }
};
/*
above is my solution
定义一个数组，类似于哈希表
如果哈希表内的数不为0，那么返回该数
可对数据进行如下定义
        int n = nums.size();
        vector<int>a(n, 0); 0表示初始化为0 
*/ 

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
            // 如果在第i位的数不等于i
            {
                if (nums[i] == nums[nums[i]])
                { // 如果在第i位的数等于在第nums[i]位的数，则找到了重复值
                    return nums[i];
                }
                else
                {
                    int temp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[temp] = temp;
                }
            }
        }
        return -1;
    }
};

/*
above is another solution
思路：
从头开始遍历，如果没有重复值，那么第i个位置的值应该等于i
 目的是去查找冲突
 将第值为i的元素放在num[i]的位置上 
*/ 
