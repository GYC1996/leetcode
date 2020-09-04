//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
//如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
//例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
//
//[["a","b","c","e"],
//["s","f","c","s"],
//["a","d","e","e"]]
//
//但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>sign(board.size(), vector<int>(board[0].size(), 0));
        int i, j;
        int point = 0;
        for (i = 0; i < board.size(); i++){
            for (j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[point]){
                    point = point + 1;
                    if (search(i, j, board, word, point) == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool search(int i, int j, vector<vector<char>>& board, string word, int point){
        bool val;
        if (board[i-1][j] == word[point] && i-1 >= 0){
            point = point + 1;
            if (point > word.length()){
                return true;
            }
            i = i - 1;
            val = search(i, j, board, word, point);
        }
        else if (board[i][j+1] == word[point] && j+1 < board[0].size()){
            point = point + 1;
            if (point > word.length()){
                return true;
            }
            j = j + 1;
            val = search(i, j, board, word, point);
        }
        else if (board[i+1][j] == word[point] && i+1 < board.size()){
            point = point + 1;
            if (point > word.length()){
                return true;
            }
            i = i + 1;
            val = search(i, j, board, word, point);
        }
        else if (board[i][j-1] == word[point] && j-1 >= 0){
            point = point + 1;
            if (point > word.length()){
                return true;
            }
            j = j - 1;
            val = search(i, j, board, word, point);
        }
        else{
            point = point - 1;
        }
    }
};

/*
先对每个格子位置进行遍历
送入搜索
分别搜索上下左右的位置 
*/ 

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return false;
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[0].size(); ++j)
            {
                // 使用回溯法解题
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w)
    {
        // 如果索引越界，或者值不匹配，返回false
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[w]) return false;
        if(w == word.length() - 1) return true;
        char temp = board[i][j];
        board[i][j] = '\0'; // 将当前元素标记为'\0'，即一个不可能出现在word里的元素，表明当前元素不可再参与比较
        if(dfs(board,word,i-1,j,w+1) 
        || dfs(board,word,i+1,j,w+1) 
        || dfs(board,word,i,j-1,w+1) 
        || dfs(board,word,i,j+1,w+1))
        {
            // 当前元素的上下左右，如果有匹配到的，返回true
            return true;
        }
        board[i][j] = temp; // 将当前元素恢复回其本身值
        return false;
    }
};
