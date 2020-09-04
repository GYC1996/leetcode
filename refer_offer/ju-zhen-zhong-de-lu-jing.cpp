//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
//���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
//���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ������
//
//[["a","b","c","e"],
//["s","f","c","s"],
//["a","d","e","e"]]
//
//�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�


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
�ȶ�ÿ������λ�ý��б���
��������
�ֱ������������ҵ�λ�� 
*/ 

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return false;
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[0].size(); ++j)
            {
                // ʹ�û��ݷ�����
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w)
    {
        // �������Խ�磬����ֵ��ƥ�䣬����false
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[w]) return false;
        if(w == word.length() - 1) return true;
        char temp = board[i][j];
        board[i][j] = '\0'; // ����ǰԪ�ر��Ϊ'\0'����һ�������ܳ�����word���Ԫ�أ�������ǰԪ�ز����ٲ���Ƚ�
        if(dfs(board,word,i-1,j,w+1) 
        || dfs(board,word,i+1,j,w+1) 
        || dfs(board,word,i,j-1,w+1) 
        || dfs(board,word,i,j+1,w+1))
        {
            // ��ǰԪ�ص��������ң������ƥ�䵽�ģ�����true
            return true;
        }
        board[i][j] = temp; // ����ǰԪ�ػָ����䱾��ֵ
        return false;
    }
};
