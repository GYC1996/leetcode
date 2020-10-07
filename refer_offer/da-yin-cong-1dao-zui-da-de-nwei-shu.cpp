//�������� n����˳���ӡ���� 1 ������ n λʮ��������
//�������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

class Solution {
public:
    vector<int> printNumbers(int n) {
        int edge = pow(10, n);
        vector<int>v;
        for (int i = 1; i < edge; i++){
            v.push_back(i);
        }
        return v;
    }
};

/*
����Ϊ��д��������Ϊ����д�� 
*/ 

class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');
		// �ȳ�ʼ��ÿһλ����0 
		while (!Increment(number))
		{
			saveNumber(number);
		}
		return res;
	}
	bool Increment(string& number) {
		bool isOverflow = false;
		int nTakeOver = 0;
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--)
		{ // �Ӹ�λ��ʼ���� 
			int nSum = number[i] - '0' + nTakeOver; // ���������ж��Ƿ��λ 
			if (i == nLength - 1)
			{
				nSum++;
			}
			if (nSum >= 10)
			{ // ��Ҫ��λ 
				if (i == 0)
				{
					isOverflow = true;
				}
				else
				{ // ������һλ�ļ��� 
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';
				}
			}
			else
			{ // ����Ҫ��λ���ͶԸ�λ���� +1 
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number)
	{
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			// �ж�ĩλ�Ƿ�Ϊ 0��  
			if (!isBegin0)
			{
				s += *it;
			}
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};
