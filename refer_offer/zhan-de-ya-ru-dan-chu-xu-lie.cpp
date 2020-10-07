//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ����磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У�
//���� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У��� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ�������

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
ֱ���ж� �����Ƿ����pop 
*/ 

