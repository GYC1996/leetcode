//�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

class Solution {
public:
    bool isPalindrome(int x) {
        // deque<int>q;
        if (x < 0){
            return false;
        }
        if (x % 10 == 0 && x != 0){
            return false;
        }
        int sum = 0;
        while (x > sum){
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (x == sum || x == sum / 10);
    }
};

// ˼·��
// 1.�����Լ�ĩλΪ 0 ����һ�����ǻ�����
// 2.���������ֳ���һ�����ϣ�ͨ���ԱȽ���õ�
// 3.�������ٳ���һλ ż��ֱ���ж� 
 

