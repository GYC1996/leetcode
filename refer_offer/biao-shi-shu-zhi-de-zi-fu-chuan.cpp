//��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
//���磬�ַ���"+100"��"5e2"��"-123"��"3.1416"��"-1E-16"��"0123"����ʾ��ֵ��
//��"12e"��"1a3.14"��"1.2.3"��"+-5"��"12e+5.4"�����ǡ�

//��Ҫ˼·�� 
//���ȰѴ����ŵ�������ȥ����Ȼ����Ϊe�ĺ��治������.С����С�����������e�� 
//����ȥ�ж����=='.'�����������Ѻ�����޷��ŵ�����ȥ���������������e��
//Ҳȥ�Ѻ�����з��ŵ�����ȥ���� ������������index�������һλ����ô��Ϊfalse�� 
//������������index�����һλ����Ϊtrue�� 
//�������������߲����������13.45a6 .���ֻ���ߵ�a�ͻ����������Ϊfalse��

// e �ĺ��治����С���� �������з��� 
// С����ǰ��ֻҪһ�������־����� 
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
            has_num = true; // ���ʼ�ж��Ƿ�������
        if (s[index] == '.'){
            index++;
        }  
        pre_index = index;
        while (s[index] >= '0' && s[index] <= '9'){
            index++;
        }
        if (pre_index < index)
            has_num = true; // С���������
        else {
            has_num = has_num; // ȷ��С����֮ǰ�Ƿ�������
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
            has_num = has_num && has_num2; // e�Ļ�֮ǰ֮��Ҫ�����ֲ��� 
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
