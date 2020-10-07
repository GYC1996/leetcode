//����һ�����󣬰��մ���������˳ʱ
//���˳�����δ�ӡ��ÿһ�����֡�

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
����Ϊʹ��ö�ٵ��㷨�о�������������ֱ���п��� 
*/ 
/*
����ʹ�ø����м����Եط��� 
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
            int next_j = j + direction[directionIndex][1]; //������һ���ڵ� 
            if (next_i < 0 || next_i >= matrix.size() || next_j < 0 || next_j >= matrix[0].size() || visited[next_i][next_j] == true){
            	// ��������ڱ�Ե�ڵ㣬�Ǿ�ת�÷��� 
                directionIndex = (directionIndex + 1) % 4;
            }
            // ���ת���˷������µع���Ҳ��������ǰ�㣬�����ڷ��ʵڶ��� 
            i += direction[directionIndex][0];
            j += direction[directionIndex][1];
        }
        return a;
    }
};
