//дһ������ StrToInt��ʵ�ְ��ַ���ת��������������ܡ�����ʹ�� atoi �����������ƵĿ⺯����
//
//���ȣ��ú����������Ҫ�������õĿ�ͷ�ո��ַ���ֱ��Ѱ�ҵ���һ���ǿո���ַ�Ϊֹ��
//
//������Ѱ�ҵ��ĵ�һ���ǿ��ַ�Ϊ�����߸���ʱ���򽫸÷�����֮���澡���ܶ���������������������Ϊ�������������ţ������һ���ǿ��ַ������֣���ֱ�ӽ�����֮�������������ַ�����������γ�������
//
//���ַ���������Ч����������֮��Ҳ���ܻ���ڶ�����ַ�����Щ�ַ����Ա����ԣ����Ƕ��ں�����Ӧ�����Ӱ�졣
//
//ע�⣺������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ����ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ������ĺ�������Ҫ����ת����
//
//���κ�����£����������ܽ�����Ч��ת��ʱ���뷵�� 0

class Solution {
public:
    int strToInt(string str) {
        int i = 0, flag = 1;
        long res = 0;
        while (str[i] == ' '){
            i++;
        }
        if (str[i] == '-'){
            flag = -1;
        }
        if (str[i] == '+' || str[i] == '-'){
            i++;
        }
        for (; i < str.size() && str[i] >= '0' && str[i] <= '9'; i++){
            res = res * 10 + str[i] - '0';
            if (res > INT_MAX){
                if (flag == 1){
                    return INT_MAX;
                }
                if (flag == -1){
                    return INT_MIN;
                }
            }
        }
        return flag * res;
    }
};
