class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int a[100000] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            if (a[nums[i]] == 1)
            {
                return nums[i];
            }
            else
            {
                a[nums[i]] = 1;
            }
        }
        return 0;
    }
};
/*
above is my solution
����һ�����飬�����ڹ�ϣ��
�����ϣ���ڵ�����Ϊ0����ô���ظ���
�ɶ����ݽ������¶���
        int n = nums.size();
        vector<int>a(n, 0); 0��ʾ��ʼ��Ϊ0 
*/ 

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
            // ����ڵ�iλ����������i
            {
                if (nums[i] == nums[nums[i]])
                { // ����ڵ�iλ���������ڵ�nums[i]λ���������ҵ����ظ�ֵ
                    return nums[i];
                }
                else
                {
                    int temp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[temp] = temp;
                }
            }
        }
        return -1;
    }
};

/*
above is another solution
˼·��
��ͷ��ʼ���������û���ظ�ֵ����ô��i��λ�õ�ֵӦ�õ���i
 Ŀ����ȥ���ҳ�ͻ
 ����ֵΪi��Ԫ�ط���num[i]��λ���� 
*/ 
