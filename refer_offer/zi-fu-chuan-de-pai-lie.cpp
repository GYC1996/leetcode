//����һ���ַ�������ӡ�����ַ������ַ����������С�
//�����������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ��

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
            if (!judge(s, loc, i)){ // s[i] �� s[id,i) ֮��û�г��ֹ����ܽ��н���
									// ������ֵĻ��� �൱��������λ��λ�û������ͬ��Ԫ��
									// ���� a b a b
									// a ��ڶ��� b ���н��������������ĸ� b ���н�������ô��һ��λ�þ����γ����� b�����������ظ����� 
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
ʹ��������ȱ�����������
 
*/ 
