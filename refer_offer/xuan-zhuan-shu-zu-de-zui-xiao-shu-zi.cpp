//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
//例如，数组?[3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int begin = 0;
        int end = numbers.size() - 1;
        int middle = 0;
        while (begin < end){
            middle = (begin + end) / 2;
            // cout << begin << " " << end << " " << middle <<endl;
            if (numbers[middle] > numbers[end]){
                begin = middle + 1;
            }
            else if (numbers[middle] < numbers[end]){
                end = middle;
            }
            else{
                end--;
            }
        }
        return numbers[begin];
    }
};

/*
采用二分查找的方法
将中间的数和end进行对比
如果中间的数大于end的数，那么最小的数一定在中间这个数和end之间，但一定不是中间这个数
如果中间的数小于end的数，那么最小的数一定在开始的数和中间这个数之间，有可能是中间这个数
当两者相等时，因为最小的值有可能在中间数的两边出现，因此不能随意下定义，可暂时忽略end数，因此对end - 1
 
 
*/ 


