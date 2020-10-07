//���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
//2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14

// ˳�ӵ��������� 0 �⣬���е�Ԫ�ز����ظ�
//             �� 0 �⣬���е�Ԫ������ max - min < 5

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // return false;
        unordered_map<int, int>mymap;
        int i = 0;
        int min = 14;
        int max = -1;
        for (i = 0; i < nums.size(); i++){
            mymap[nums[i]]++;
            if (nums[i] != 0){
                if (mymap[nums[i]] > 1){
                    return false; // �������ظ�ֱ���˳� 
                }
                if (nums[i] < min){
                    min = nums[i];
                }
                if (nums[i] > max){
                    max = nums[i];
                }
            }
        }
        if (mymap[0] == 5){
            return true;
        }
        return max-min<5; // �ж�����Ƿ�С�� 5 
    }
}; 

