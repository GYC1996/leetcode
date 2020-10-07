//�붨��һ�����в�ʵ�ֺ��� max_value �õ�����������ֵ��
//Ҫ����max_value��push_back �� pop_front �ľ�̯ʱ�临�Ӷȶ���O(1)

class MaxQueue {
public:
    // deque<int>q, q_max;
    deque<int>q_max;
    queue<int>q;
    MaxQueue() {

    }
    
    int max_value() {
        if (q_max.empty()){
            return -1;
        }
        return q_max.front();
    }
    
    void push_back(int value) {
        // cout << "push_back: " << value << endl;
        while (!q_max.empty() && q_max.back() <= value){
            q_max.pop_back();
        }
        q_max.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty()){
            return -1;
        }
        if (q.front() == q_max.front()){
            q_max.pop_front();
        }
        int value = q.front();
        cout << value << endl;
        q.pop();
        return value;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
 
 // ˫�˶���ά�� �����ݼ�ջ 
