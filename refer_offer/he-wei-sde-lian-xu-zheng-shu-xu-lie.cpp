//����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
//
//�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>a;
        int limit = target / 2;
        int i = 0, j = 0;
        for (i = 1; i <= limit; i++){
            int sum = 0;
            for (j = i; ; j++){
                sum += j;
                if (sum > target){
                    sum = 0;
                    break;
                }
                else if (sum == target){
                    vector<int>list;
                    for (int k = i; k <= j; k++){
                        list.push_back(k);
                    }
                    a.push_back(list);
                    sum = 0;
                    break;
                }
            }
        }
        return a;
    }
};

/*
����ö�ٷ�
��Ϊ�����������ϳɣ����limitΪtarget/2������֮��������������Ӷ������target�����ֻ��Ҫ���Ե�target����
i �� 1 �� limit ��Ϊ��ʼ�ڵ�
ѡ�� j �� i ��ʼ�����ۼӣ�ֱ����Ȼ�����˳� ѭ�� ��������һ�� i �Ŀ�ʼ 
*/ 

/*
�ɲ�����һ�ַ��������Ƿ���� y ��ʹ�ô� i �� y �ĺ͵���target 
*/ 

