//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У�
//���� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)

// ʹ��һ������ջ��ʵ�ִ洢��ǰ��Сֵ 
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
            min_s.push(x); // ֻ������ǰ��С��
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
