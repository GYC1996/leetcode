//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
//序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        if (pushed.size() == 0){
            return true;
        }
        int i = 0, j = 0;
        while (i < pushed.size()){
            s.push(pushed[i]);
            i++;
            while (!s.empty() && s.top() == popped[j]){
                j++;
                s.pop();
            }
        }
        if (j != popped.size()){
            return false;
        }
        return true;
    }
};

/*
直接判断 顶端是否等于pop 
*/ 

