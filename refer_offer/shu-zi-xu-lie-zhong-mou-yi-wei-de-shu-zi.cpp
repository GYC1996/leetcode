//������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�
//����������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵ�

class Solution {
public:
    int findNthDigit(int n) {
    	long m = n; 
        if (m == 0){
            return 0;
        }
        int bit = 1;
        while (m > 0){
            m = m - 9 * pow(10, bit-1) * bit;
            bit += 1;
        }
        bit -= 1;
        m += 9 * pow(10, bit-1) * bit; //��������� bit λ���ֵĵ� m ������ 
        m = m - 1; // m-1��Ҫ��Ϊ������0λ������1λ 
        //�������bitλ���ĵ�n��λ�� ��������n=9 ��ʱn=9�� bit=1
        long num = pow(10, bit-1) + m / bit; //��������ĸ���������9
        int b = m % bit; // num�ĵ�bλ
        cout << num << " " << bit << " " << b << ' ' << n << endl;
        return (num / int(pow(10, bit-b-1))) % 10;
    }
};
