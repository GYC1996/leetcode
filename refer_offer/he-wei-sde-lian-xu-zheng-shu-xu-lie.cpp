//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//
//序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>a;
        int limit = target / 2;
        int i = 0, j = 0;
        for (i = 1; i <= limit; i++){
            int sum = 0;
            for (j = i; ; j++){
                sum += j;
                if (sum > target){
                    sum = 0;
                    break;
                }
                else if (sum == target){
                    vector<int>list;
                    for (int k = i; k <= j; k++){
                        list.push_back(k);
                    }
                    a.push_back(list);
                    sum = 0;
                    break;
                }
            }
        }
        return a;
    }
};

/*
暴力枚举法
因为至少两个数合成，因此limit为target/2，代表之后任意两个数相加都会大于target，因此只需要测试到target就行
i 从 1 到 limit 作为起始节点
选择 j 从 i 开始进行累加，直到相等或大于退出 循环 ，设置下一个 i 的开始 
*/ 

/*
可采用另一种方法计算是否存在 y ，使得从 i 到 y 的和等于target 
*/ 

