//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
//������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ

class Solution {
public:
    bool judge(vector<int>& postorder, int begin, int end){
        int m, i = 0;
        if (begin >= end){
            return true;
        }
        for (i = begin; i < end; i++){
            if (postorder[i] > postorder[end]){
                m = i; // m Ϊ ����������� 
                break;
            }
        }
        for (i = m; i < end && postorder[i] > postorder[end]; i++) ;	 
        return  (i == end) && judge(postorder, begin, m-1) && judge(postorder, m, end-1) ;
    }
    bool verifyPostorder(vector<int>& postorder) {
        int begin = 0;
        int end = postorder.size()-1;
        return judge(postorder, begin, end);
    }
};

/*
�������������ص��� ������С�ڸ��ڵ㣬���������ڸ��ڵ�
ĩ��Ϊ���ڵ㣬ͨ���Ա�����ڵ�Ĵ�С��λ�������� 
Ȼ��ݹ��ж� 
*/
