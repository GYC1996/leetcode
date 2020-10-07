//������������ arr ���ҳ�������С�� k ������
//���磬����4��5��1��6��2��7��3��8��8�����֣�
//����С��4��������1��2��3��4

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0){
            return {};
        }
        priority_queue<int> q;
        vector<int> a;
        int i;
        for (i = 0; i < k; i++){
            q.push(arr[i]);
        }
        for (i = k; i < arr.size(); i++){
            if (arr[i] < q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        while (!q.empty()){
            a.push_back(q.top());
            q.pop();
        }
        return a;
    }
};

/*
�������ȶ��У�ÿ���滻������Ԫ�أ�֮���������ľ�����С��Ԫ�� 
*/ 

// priority_queue<int> que; ���ﹹ��int���������ͣ�Ĭ�����ȼ�(���ֵ����) 
// priority_queue<int,vector<int>,less<int> >que1;//���ֵ����            ����һ������Ϊ�������ͣ��ڶ���Ϊ�������ͣ�������Ϊ�Ƚ����͡��� 
// priority_queue<int,vector<int>,greater <int> >que2;//��Сֵ���� 
// ���߿��Խ����Զ��� 

//struct cmp1
//{
//    bool operator ()(int &a,int &b)
//    {
//       return a < b;//���ֵ����  
//    }     
//};
//struct cmp2
//{
//    bool operator() (int &a,int &b)
//    {
//     return a > b;//��Сֵ����
//    }            
//};
////����
//priority_queue<int,vector<int>,cmp1>que1;//���ֵ����
//priority_queue<int,vector<int>,cmp2>que2;//��Сֵ����
