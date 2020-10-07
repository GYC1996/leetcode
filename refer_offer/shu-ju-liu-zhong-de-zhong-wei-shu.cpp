//��εõ�һ���������е���λ����
//������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
//������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ

// ͨ��ά��һ���󶥶Ѻ�һ��С����������
// ����������ʱ���󶥶Ѵ�һ��ż��ʱ��Ϊһ��

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > qs; // �󶥶�
    // ÿ����������Ǹ������洢��С����һ��Ԫ��
    priority_queue<int, vector<int>, greater<int> > qb; // С����
    // ÿ�������С���Ǹ������洢�ϴ����һ��Ԫ��
    MedianFinder() {

    }
    
    void addNum(int num) {
        qb.push(num); //ÿ���ȴ���С����,��Ŵ���Ǹ����
        qs.push(qb.top()); // С���ѵ�Ԫ�ط���󶥶�
        qb.pop();
        if (qs.size() - qb.size() > 1){
            qb.push(qs.top()); // qb top��С��
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

