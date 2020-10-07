//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
//调用 min、push 及 pop 的时间复杂度都是 O(1)

// 使用一个辅助栈来实现存储当前最小值 
//

class MinStack {
public:
    stack<int>s;
    stack<int>min_s;
    // int min_value = INT_MAX;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if (min_s.empty() || x <= min_s.top()){
            min_s.push(x); // 只保留当前最小的
            // min_value = x;
        }
    }
    
    void pop() {
        if (s.top() == min_s.top()){
            s.pop();
            min_s.pop();
        }
        else{
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
