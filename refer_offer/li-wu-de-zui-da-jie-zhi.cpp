//��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0����
//����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�
//����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ������

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int size0 = grid.size(), size1 = grid[0].size();
        vector<vector<int>>count(size0, vector<int>(size1, 0));
        count[0][0] = grid[0][0];
        int i = 0, j = 0;
        for (i = 1; i < size1; i++){
            count[0][i] = count[0][i-1] + grid[0][i];
        }
        for (i = 1; i < size0; i++){
            count[i][0] = count[i-1][0] + grid[i][0];
        }
        for (i = 1; i < size0; i++){
            for (j = 1; j < size1; j++){
                count[i][j] = max(count[i-1][j]+grid[i][j], count[i][j-1]+grid[i][j]);
            }
        }
        return count[size0-1][size1-1];
    }
};

/*
ʹ�ö�̬�滮��˼· 
*/ 

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int size0 = grid.size(), size1 = grid[0].size();
        int i = 0, j = 0;
        for (j = 1; j < size1; j++){
            grid[0][j] += grid[0][j-1];
        }
        for (i = 1; i < size0; i++){
            grid[i][0] += grid[i-1][0];
        }
        for (i = 1; i < size0; i++){
            for (j = 1; j < size1; j++){
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[i-1][j-1];
    }
};
