//输入一个字符串，打印出该字符串中字符的所有排列。
//你可以以任意顺序返回这个字符串数组，但里面不能有重复元素

class Solution {
public:
    bool judge (string s, int begin, int end){
        for (int i = begin; i < end; i++){
            if (s[i] == s[end]){
                return true;
            }
        }
        return false;
    }
    void dfs(string s, int loc, vector<string> &v){
        if (loc == s.length()-1){
            v.push_back(s);
            return ;
        }
        for (int i = loc; i < s.length(); i++){
            if (!judge(s, loc, i)){ // s[i] 在 s[id,i) 之间没有出现过才能进行交换
									// 如果出现的话， 相当于索引定位的位置会出现相同的元素
									// 例如 a b a b
									// a 与第二个 b 进行交换，如果在与第四个 b 进行交换，那么第一个位置就两次出现了 b，后面会出现重复现象 
                swap(s[i], s[loc]);
                dfs(s, loc+1, v);
                swap(s[i], s[loc]);
            }
        }
    }
    vector<string> permutation(string s) {
        vector<string>v;
        dfs(s, 0, v);
        return v;
    }
};
/*
使用深度优先遍历进行搜索
 
*/ 
