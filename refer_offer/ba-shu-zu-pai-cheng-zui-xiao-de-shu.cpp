//����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ��
// c++ ���浥���ű�ʾ�ַ���˫���ű�ʾ�ַ��� 
// string ���� string s = s1[0]+s1[1] 
// ֻ�� string = ""    string += (s1[0]+s1[1])
// s.substr(idx, 2) �ַ�����ȡ 

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

// �ж������ַ� s1+s2 < s2+s1 

#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1 = "12";
	string s2 = "13";
	cout << s1+s2 << " " << s2+s1 << endl; //  1213 1312 
	s1 = '12'; // ֻ��ȡ���һ���ַ����õ����ŵĻ� 
	s2 = '13'; // ��һ����� 2 ��һ����� 3 
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
        if (loc < s.size()-1 && judge(s, loc)){ // �ж��Ƿ������λ�������� 
            cout << s[loc]+s[loc+1] << "True";
            count2 = dfs(s, loc+2);
        }
        cout << loc << " " << count1 << " " << count2 << endl;
        return count1+count2;
    }
    int translateNum(int num) {
        // 0 - 25 ���ܱ�ʾ
        string s = to_string(num);
        int loc = 0;
        int count = dfs(s, loc);
        return count;
    }
};
/*
��ȱ������� 
*/ 
