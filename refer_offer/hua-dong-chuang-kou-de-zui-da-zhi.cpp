//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

// 使用双端队列进行描述
// 双端队列存储下标
// 保留当前窗口最大的值位于队尾，保证队尾元素肯定最大 
// 从队头维护窗口大小


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>a;
        deque<int>q;
        for (int i = 0; i < nums.size(); i++){
            while (!q.empty() && nums[i] >= nums[q.back()]){ // 从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标 
                q.pop_back();
            }
            while (!q.empty() && q.front() < i-k+1){ // 当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出 
                q.pop_front();
            }
            q.push_back(i);
            if (i >= k-1){
                a.push_back(nums[q.front()]); // 当滑动窗口首地址i大于等于size时才开始写入窗口最大值 
            } 
        }
        return a;
    }
}; 
