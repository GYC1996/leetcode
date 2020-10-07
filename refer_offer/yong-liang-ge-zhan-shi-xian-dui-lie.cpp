//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead?操作返回 -1 )

class CQueue {
    stack<int> stack1;
    stack<int> stack2;
public:
    CQueue() {
        while (!stack1.empty()){
            stack1.pop();
        }
        while (!stack2.empty()){
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
           }
        }
        if (stack2.empty()){
            return -1;
        }
        else{
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};

/*
具体思路如下：
当第二个栈不为空，就从第二个栈弹出
当第二个栈为空时，将第一个栈倒入第二个栈然后再从第二个栈弹出 
*/ 

