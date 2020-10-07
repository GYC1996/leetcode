#include<utility>
#include<vector> 
#include<iostream>
#include<queue>
using namespace std;
int main(){
	pair<int, int>p, p1;
	// ��� pair ����Ϊ p 
	vector<pair<int, int> >v; 
	// �� pair Ƕ�� vector
	queue<pair<int, int> >q;
	p = make_pair(0, 0);
//	p = pair<int, int>(1, 1);
	p.first+=1;
	p.second+=1;
	v.push_back(p);
	p1 = v[0];
	cout << p1.first;
	return 0;  
}

//������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
//һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
//Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
//���ʸû������ܹ�������ٸ����ӣ�

class Solution {
public:
    int get_num(int num){
        int sum = 0;
        while (num > 0){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int movingCount(int m, int n, int k) {
        if (k == 0){
            return 1;
        }
        vector<vector<int>>visited(m, vector<int>(n, 0));
        queue<pair<int, int>>q;
        pair<int, int>p(0, 0);
        q.push(p);
        int ans = 1;
        while (!q.empty()){
            p = q.front();
            q.pop();
            for (int i = 0; i < 2; i++){
                int x, y;
                if (i == 0){
                    x = p.first;
                    y = p.second + 1;
                }
                if (i == 1){
                    x = p.first + 1;
                    y = p.second;
                }
                if (x < 0 || x >= m || y < 0 || y >= n || get_num(x) + get_num(y) > k || visited[x][y]){
                    continue; //�ڲ���֮ǰ�����ж� 
                }
                visited[x][y] = 1;
                ans ++;
                q.push(make_pair(x, y));
            }
        }
        return ans;
    }
};

/*
����˼·��
ʹ�ù�����ȱ�������������ֻ�������Һ��������� 
*/


 
