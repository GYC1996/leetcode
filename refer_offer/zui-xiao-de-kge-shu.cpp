//输入整数数组 arr ，找出其中最小的 k 个数。
//例如，输入4、5、1、6、2、7、3、8这8个数字，
//则最小的4个数字是1、2、3、4

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
采用优先队列，每次替换掉最大的元素，之后留下来的就是最小的元素 
*/ 

// priority_queue<int> que; 这里构造int型数据类型，默认优先级(最大值优先) 
// priority_queue<int,vector<int>,less<int> >que1;//最大值优先            （第一个参数为数据类型，第二个为容器类型，第三个为比较类型。） 
// priority_queue<int,vector<int>,greater <int> >que2;//最小值优先 
// 或者可以进行自定义 

//struct cmp1
//{
//    bool operator ()(int &a,int &b)
//    {
//       return a < b;//最大值优先  
//    }     
//};
//struct cmp2
//{
//    bool operator() (int &a,int &b)
//    {
//     return a > b;//最小值优先
//    }            
//};
////构造
//priority_queue<int,vector<int>,cmp1>que1;//最大值优先
//priority_queue<int,vector<int>,cmp2>que2;//最小值优先
