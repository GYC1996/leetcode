//����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ���

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
�ж���һ��Ԫ���Ƿ��ڵ�ǰ�ַ�������
ʹ�� set ����Ҫ�����ܾã�ʹ��find������Ҫ���� 
*/

// ��һ�ֽⷨ����
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> chars;
        for(int i = 0; i < s.size(); i ++){
        	// �ӵ�һ��Ԫ�ؿ�ʼ����set 
        	// ĳ��Ԫ��Ϊͷֻ��һ����ִ� 
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

// ����һ�ֽⷨ
// ���ʹ���� unordered set 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        if(s.size() == 0) return 0;
        unordered_set<char> chars;
        int right = 0;
        for(int left = 0; left < s.size(); left ++){
        	// �� left ����ѭ�� 
            while(right < s.size() && !chars.count(s[right])){
                chars.insert(s[right]);
                right ++;
                // ���Ԫ�ش������棬��ô��ѭ���˳��������ƶ���ָ�� 
            }
            maxLen = max(maxLen, right - left);
            if(right == s.size()) break;
            chars.erase(s[left]);
        }
        return maxLen;
    }
}





