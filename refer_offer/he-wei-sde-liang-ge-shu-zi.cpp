//����һ����������������һ������s���������в�����������
//ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s�����������һ�Լ��ɡ�

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin <= end){
            if (nums[begin] + nums[end] > target){
                end = end -1;
            }
            else if (nums[begin] + nums[end] < target){
                begin = begin + 1;
            }
            else{
                break;
            }
        }
        vector<int>a(2, 0);
        a[0] = nums[begin];
        a[1] = nums[end];
        return a;
    }
};

/*
˫ָ�룬һ��ָ��ͷ����һ��ָ��β��
���С��target��ͷָ������ƶ���
��Ӵ���target��βָ����ǰ�ƶ���
���ʱֱ����� 
*/ 


