//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
//你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
//给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物

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
使用动态规划的思路 
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
