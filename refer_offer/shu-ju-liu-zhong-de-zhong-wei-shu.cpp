//如何得到一个数据流中的中位数？
//如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值

// 通过维护一个大顶堆和一个小顶堆来操作
// 可设置奇数时，大顶堆大一，偶数时各为一半

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > qs; // 大顶堆
    // 每次输出最大的那个数，存储较小的那一半元素
    priority_queue<int, vector<int>, greater<int> > qb; // 小顶堆
    // 每次输出最小的那个数，存储较大的那一半元素
    MedianFinder() {

    }
    
    void addNum(int num) {
        qb.push(num); //每次先存入小顶堆,存放大的那个半堆
        qs.push(qb.top()); // 小顶堆的元素放入大顶堆
        qb.pop();
        if (qs.size() - qb.size() > 1){
            qb.push(qs.top()); // qb top是小的
            qs.pop();
        }
    }
    
    double findMedian() {
        if (qs.size() == 0){
            return NULL;
        }
        if (qb.size() == qs.size()){
            cout << qb.top() << " " << qs.top() << endl;
            return ((qb.top()+qs.top())/2.0);
        }
        else{
            cout << qb.top() << endl;
            return qs.top();
        }
    }
}; 

