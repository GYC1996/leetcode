//����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

//����ⲻ��Ҫ���ٶ���Ķ��пռ����洢ÿһλ����

class Solution {
public:
    int reverse(int x) {
        long sum = 0;
        while (x != 0){
            int temp = x % 10;
            sum = sum * 10 + temp;
            x = x / 10;
        }
        if (sum >= INT_MAX || sum <= INT_MIN)
            sum = 0;
        return sum;
    }
}; 

// -123 % 10 =  -3    123 / 10 = -12
 

