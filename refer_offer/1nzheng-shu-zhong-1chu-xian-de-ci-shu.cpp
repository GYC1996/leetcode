//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
//
//例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

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

//我们假设高位为high，当前位为cur，低位为low，i代表着需要统计的位置数（1对应个位，10对应十位，100对应百位），则对每一位的个数count有：
//cur=0,count = high*i;
//cur=1,count=high*i+low+1;
//cur>1,count=high*i+i
//最终累加所有位置上的个数即最终答案。

