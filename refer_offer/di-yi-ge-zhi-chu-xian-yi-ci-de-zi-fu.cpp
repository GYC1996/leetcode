//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母

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
使用哈希表 
*/ 
