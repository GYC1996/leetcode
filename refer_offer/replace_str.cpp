//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
// �Ƚϼ� 
class Solution {
public:
    string replaceSpace(string s) {
        string str;
        int j = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] != ' '){
                str.push_back(s[i]);
            }
            else{
                str.push_back('%');
                str.push_back('2');
                str.push_back('0');
            }
            cout << i <<endl;
        }
        return str;
    }
};
