#include<utility>
#include<vector> 
#include<iostream>
#include<queue>
using namespace std;
int main(){
	pair<int, int>p, p1;
	// 这个 pair 命名为 p 
	vector<pair<int, int> >v; 
	// 将 pair 嵌入 vector
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

//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
//一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
//也不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
//请问该机器人能够到达多少个格子？

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
                    continue; //在插入之前进行判断 
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
具体思路：
使用广度优先遍历搜索，而且只基于向右和向下搜索 
*/


 
