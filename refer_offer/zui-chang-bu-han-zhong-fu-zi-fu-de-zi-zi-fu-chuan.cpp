//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0){
            return 0;
        }
        int i = 0, j = 1;
        int max = 1;
        string temp = s.substr(i, j);
        string::size_type position;
        // temp = s.substr(i, j);
        cout << temp << endl;
        for (j = 1; j < s.size()+1; j++){
            max = max > temp.size() ? max : temp.size();
            position = temp.find(s[j]);
            if (position != s.npos){
                i = i + position + 1;
                temp = s.substr(i, j+1-i);
            }
            else{
                temp = s.substr(i, j+1-i);
            }
            cout << i << " " << j+1 << " " << temp << endl;
        }
        return max;
    }
};

/*
判断下一个元素是否在当前字符串里面
使用 set 不需要遍历很久，使用find函数需要遍历 
*/

// 另一种解法如下
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> chars;
        for(int i = 0; i < s.size(); i ++){
        	// 从第一个元素开始构建set 
        	// 某个元素为头只有一个最长字串 
            int len = 1;
            chars.clear();
            chars.insert(s[i]);
            for(int j = i + 1; j < s.size(); j ++){
                if(chars.count(s[j])){
                    break;
                } 
                else {
                    chars.insert(s[j]);
                    len ++;
                }
            }
            cout << len << endl;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

// 还有一种解法
// 这边使用了 unordered set 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        if(s.size() == 0) return 0;
        unordered_set<char> chars;
        int right = 0;
        for(int left = 0; left < s.size(); left ++){
        	// 对 left 进行循环 
            while(right < s.size() && !chars.count(s[right])){
                chars.insert(s[right]);
                right ++;
                // 如果元素存在里面，那么从循环退出，继续移动左指针 
            }
            maxLen = max(maxLen, right - left);
            if(right == s.size()) break;
            chars.erase(s[left]);
        }
        return maxLen;
    }
}





