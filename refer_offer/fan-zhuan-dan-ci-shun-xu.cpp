//����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
//Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "�������"student. a am I"

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string res, str;
        istringstream ss(s);
        while (ss >> str){
            stk.push(str);
            stk.push(" ");
        }
        if (!stk.empty()){
            stk.pop();
        }
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

