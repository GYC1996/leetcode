//���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո� s ֻ����Сд��ĸ

class Solution {
public:
    char firstUniqChar(string s) {
        if (s == ""){
            return ' ';
        }
        unordered_map<char, int>mymap;
        int i = 0;
        for (i = 0; i < s.size(); i++){
            mymap[s[i]]++;
        }
        for (i = 0; i < s.size(); i++){
            if (mymap[s[i]] == 1){
                return s[i];
            }
        }
        return ' ';
    }
};

/*
ʹ�ù�ϣ�� 
*/ 
