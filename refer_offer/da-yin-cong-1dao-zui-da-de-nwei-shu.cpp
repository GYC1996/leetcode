//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
//比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

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
如上为简单写法，如下为大数写法 
*/ 

class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');
		// 先初始化每一位都是0 
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
		{ // 从个位开始增加 
			int nSum = number[i] - '0' + nTakeOver; // 用来后面判断是否进位 
			if (i == nLength - 1)
			{
				nSum++;
			}
			if (nSum >= 10)
			{ // 需要进位 
				if (i == 0)
				{
					isOverflow = true;
				}
				else
				{ // 进行下一位的计算 
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';
				}
			}
			else
			{ // 不需要进位，就对个位进行 +1 
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
			// 判断末位是否为 0，  
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
