//����һ������ n ����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
//
//���磬����12��1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        long bit = 1;
        while (1){
            long cur_bit = n / bit % 10;
            long low_bit = n % bit;
            long high_bit = n / (10 * bit);
            if (cur_bit > 1){
                count = count + (high_bit + 1) * bit;
            }
            else if (cur_bit == 1){
                count = count + high_bit * bit + low_bit + 1;
            }
            else if (cur_bit == 0){
                count = count + high_bit * bit;
            }
            if (high_bit == 0) break;
            cout << high_bit << " " << cur_bit << " " << low_bit << endl;
            bit = bit * 10;
        }
        return count;
    }
};

//���Ǽ����λΪhigh����ǰλΪcur����λΪlow��i��������Ҫͳ�Ƶ�λ������1��Ӧ��λ��10��Ӧʮλ��100��Ӧ��λ�������ÿһλ�ĸ���count�У�
//cur=0,count = high*i;
//cur=1,count=high*i+low+1;
//cur>1,count=high*i+i
//�����ۼ�����λ���ϵĸ��������մ𰸡�

