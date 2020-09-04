//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ����������������һ����ת�������ת�������СԪ�ء�
//���磬����?[3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int begin = 0;
        int end = numbers.size() - 1;
        int middle = 0;
        while (begin < end){
            middle = (begin + end) / 2;
            // cout << begin << " " << end << " " << middle <<endl;
            if (numbers[middle] > numbers[end]){
                begin = middle + 1;
            }
            else if (numbers[middle] < numbers[end]){
                end = middle;
            }
            else{
                end--;
            }
        }
        return numbers[begin];
    }
};

/*
���ö��ֲ��ҵķ���
���м������end���жԱ�
����м��������end��������ô��С����һ�����м��������end֮�䣬��һ�������м������
����м����С��end��������ô��С����һ���ڿ�ʼ�������м������֮�䣬�п������м������
���������ʱ����Ϊ��С��ֵ�п������м��������߳��֣���˲��������¶��壬����ʱ����end������˶�end - 1
 
 
*/ 


