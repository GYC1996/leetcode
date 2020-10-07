//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
// c++ 里面单引号表示字符，双引号表示字符串 
// string 不能 string s = s1[0]+s1[1] 
// 只能 string = ""    string += (s1[0]+s1[1])
// s.substr(idx, 2) 字符串截取 

//class Solution {
//public:
//    string minNumber(vector<int>& nums) {
//        vector<string>v;
//        string s="";
//        for (int i = 0; i < nums.size(); i++){
//            v.push_back(to_string(nums[i]));
//        }
//        sort(v.begin(), v.end(), [](string &s1, string &s2){return s1+s2 < s2+s1;});
//        for (int i = 0; i < v.size(); i++){
//            s += v[i];
//        }
//        return s;
//    }
//};

// 判断两个字符 s1+s2 < s2+s1 

#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1 = "12";
	string s2 = "13";
	cout << s1+s2 << " " << s2+s1 << endl; //  1213 1312 
	s1 = '12'; // 只提取最后一个字符，用单引号的话 
	s2 = '13'; // 上一个输出 2 下一个输出 3 
	cout << s1+s2 << " " << s2+s1 << endl; //  23 32 
	bool ans = s1 <= s2;
	cout << ans << endl; 
	string s3 = "";
	s3 += s1[0]+ s2[0];
	cout << s3 << endl;
}


class Solution {
public:
    bool judge(string s, int loc){
        string s1 = "";
        s1 += s[loc];
        s1 += s[loc+1];
        cout << s1 << endl;
        bool ans = (s1 <= "25" && s[loc] != '0');
        cout << ans << " ans" << endl;
        return ans;
    }
    int dfs(string s, int loc){
        int count1 = 0, count2 = 0;
        if (loc == s.size()){
            return 1;
        }
        count1 = dfs(s, loc+1);
        if (loc < s.size()-1 && judge(s, loc)){ // 判断是否符合两位数的条件 
            cout << s[loc]+s[loc+1] << "True";
            count2 = dfs(s, loc+2);
        }
        cout << loc << " " << count1 << " " << count2 << endl;
        return count1+count2;
    }
    int translateNum(int num) {
        // 0 - 25 都能表示
        string s = to_string(num);
        int loc = 0;
        int count = dfs(s, loc);
        return count;
    }
};
/*
深度遍历做的 
*/ 
