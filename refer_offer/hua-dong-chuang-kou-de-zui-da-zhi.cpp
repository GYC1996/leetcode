//����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ��

// ʹ��˫�˶��н�������
// ˫�˶��д洢�±�
// ������ǰ��������ֵλ�ڶ�β����֤��βԪ�ؿ϶���� 
// �Ӷ�ͷά�����ڴ�С


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>a;
        deque<int>q;
        for (int i = 0; i < nums.size(); i++){
            while (!q.empty() && nums[i] >= nums[q.back()]){ // �Ӻ������ε��������бȵ�ǰnumֵС��Ԫ�أ�ͬʱҲ�ܱ�֤������Ԫ��Ϊ��ǰ�������ֵ�±� 
                q.pop_back();
            }
            while (!q.empty() && q.front() < i-k+1){ // ����ǰ�����Ƴ�����Ԫ�����ڵ�λ�ã�������Ԫ�������Ӧ��num���ڴ����У���Ҫ���� 
                q.pop_front();
            }
            q.push_back(i);
            if (i >= k-1){
                a.push_back(nums[q.front()]); // �����������׵�ַi���ڵ���sizeʱ�ſ�ʼд�봰�����ֵ 
            } 
        }
        return a;
    }
}; 
