//������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead ��
//�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�(��������û��Ԫ�أ�deleteHead?�������� -1 )

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
����˼·���£�
���ڶ���ջ��Ϊ�գ��ʹӵڶ���ջ����
���ڶ���ջΪ��ʱ������һ��ջ����ڶ���ջȻ���ٴӵڶ���ջ���� 
*/ 

