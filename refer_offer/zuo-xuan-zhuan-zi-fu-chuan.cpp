//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
//�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
//���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // ͨ����ת����ʵ��
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

//ͨ��������ת����ʵ��
//abcdefg 2
// ��һ�η�ת bacdefg
// �ڶ��η�ת bagfedc
// �����η�ת cdefgab 

