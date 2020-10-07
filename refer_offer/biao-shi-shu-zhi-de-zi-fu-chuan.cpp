//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
//但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

//主要思路： 
//首先把带符号的整数先去掉，然后因为e的后面不允许有.小数，小数后面可以有e。 
//所以去判断如果=='.'。如果等于则把后面的无符号的整数去掉。如果又碰到了e。
//也去把后面的有符号的整数去掉。 如果结束后，最后index不是最后一位，那么则为false。 
//如果结束后，最后index是最后一位，则为true。 
//不符合条件的走不到最后，例如13.45a6 .最后只会走到a就会结束，所以为false。

// e 的后面不能有小数点 但可以有符号 
// 小数点前后只要一个有数字就行了 
// 

class Solution {
public:
    bool isNumber(string s) {
        s = s + '!';
        int pre_index = 0;
        bool has_num = false, has_num2 = false;
        int index = 0;
        while (s[index] == ' '){
            index++;
        }
        if (s[index] == '+' || s[index] == '-'){
            index++;
        }
        pre_index = index;
        while (s[index] >= '0' && s[index] <= '9'){
            index++;
        }
        if (pre_index < index)
            has_num = true; // 从最开始判断是否有数字
        if (s[index] == '.'){
            index++;
        }  
        pre_index = index;
        while (s[index] >= '0' && s[index] <= '9'){
            index++;
        }
        if (pre_index < index)
            has_num = true; // 小数点的数字
        else {
            has_num = has_num; // 确认小数点之前是否有数字
        }
        if (s[index] == 'e' || s[index] == 'E'){
            index++;
            if (s[index] == '+' || s[index] == '-'){
                index++;
            }
            pre_index = index;
            while (s[index] >= '0' && s[index] <= '9'){
                index++;
            }
            if (pre_index < index){
                has_num2 = true;
            }
            has_num = has_num && has_num2; // e的话之前之后都要有数字才行 
        }
        while (s[index] == ' '){
            index++;
        }
        if (s[index] == '!' && has_num){
            return true;
        }    
        return false;
    }
};
