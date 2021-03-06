//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
//为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"

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

