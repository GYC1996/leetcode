//输入一个矩阵，按照从外向里以顺时
//针的顺序依次打印出每一个数字。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }
        vector<int>a;
        int i = 0, j = 0;
        int i_begin = 0, i_end = matrix.size();
        int j_begin = 0, j_end = matrix[0].size();
        int count = 0;
        while (a.size() < matrix.size() * matrix[0].size()){
            while (j < j_end && a.size() < matrix.size() * matrix[0].size()){
                a.push_back(matrix[i][j]);
                cout <<"1:"<< matrix[i][j] <<endl;
                j++;
            }
            j = j - 1;
            i = i + 1;
            while (i < i_end && a.size() < matrix.size() * matrix[0].size()){
                a.push_back(matrix[i][j]);
                cout <<"2:"<< matrix[i][j] <<endl;
                i++;
            }
            i = i - 1;
            j = j - 1;
            while (j >= j_begin && a.size() < matrix.size() * matrix[0].size()){
                a.push_back(matrix[i][j]);
                cout <<"3:"<< matrix[i][j] <<endl;
                j--;                
            }
            j = j + 1;
            i = i - 1;
            while (i > i_begin && a.size() < matrix.size() * matrix[0].size()){
                a.push_back(matrix[i][j]);
                cout <<"4:"<< matrix[i][j] <<endl;
                i--;
            }
            i = i + 1;
            j = j + 1;
            i_begin++;
            i_end--;
            j_begin++;
            j_end--;
        }
        return a;
    }
};

/*
如上为使用枚举的算法列举了四种情况，分别进行考虑 
*/ 
/*
如下使用更具有技巧性地方法 
*/ 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }
        int total = matrix.size() * matrix[0].size();
        int i = 0, j = 0, count = 0, directionIndex = 0;
        vector<int>a;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>>visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (count = 0; count < total; count++){
            cout << i << " " << j << " " << directionIndex <<endl;
            a.push_back(matrix[i][j]);
            visited[i][j] = true;
            int next_i = i + direction[directionIndex][0];
            int next_j = j + direction[directionIndex][1]; //计算下一个节点 
            if (next_i < 0 || next_i >= matrix.size() || next_j < 0 || next_j >= matrix[0].size() || visited[next_i][next_j] == true){
            	// 如果处在于边缘节点，那就转置方向 
                directionIndex = (directionIndex + 1) % 4;
            }
            // 如果转置了方向，如下地规则也会跳过当前点，不会在访问第二遍 
            i += direction[directionIndex][0];
            j += direction[directionIndex][1];
        }
        return a;
    }
};
