class Solution {
public:
    bool helper(vector<vector<char>> board, string word, int x, int y, int idx)
    {
        if (idx == word.length())
            return true;
        
        board[x][y] = '#'; // record it's used.
        
        int m = board.size();
        int n = board[0].size();
        
        if (x+1 < m && board[x+1][y] == word[idx] &&  helper(board, word, x+1, y, idx+1))
        {
            return true;
        }
        if (x-1 >= 0 && board[x-1][y] == word[idx] && helper(board, word, x-1, y, idx+1))
        {
            return true;
        }
        if (y+1 < n && board[x][y+1] == word[idx] && helper(board, word, x, y+1, idx+1))
        {
            return true;
        }
        if (y-1 >= 0 && board[x][y-1] == word[idx] && helper(board, word, x, y-1, idx+1))
        {
            return true;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        if (word.length()==0)
            return true;
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (board[i][j] == word[0] && helper(board, word, i, j, 1))
                {    
                    return true;
                }
            }
        }
        return false;
    }
};
