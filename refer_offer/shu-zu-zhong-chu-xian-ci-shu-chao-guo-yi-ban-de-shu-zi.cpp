// ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ��������

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, current = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (current != nums[i]){
                count--;
                if (count < 0){
                    current = nums[i];
                    count = 1;
                }
            }
            else{
                count++;
            }
        }
        return current;
    }
}; 

// ����˼·
// ��Ϊ��һ�����ֳ��ֵĴ�����������һ��ĳ���
// �ó�������֮����κ�һ�����ֶ���������ȥ�����ǻ���ʣ��
//  
