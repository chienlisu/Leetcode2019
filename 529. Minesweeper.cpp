class Solution {
public:
    
    int getMines(vector<vector<char>>& board, int x, int y)
    {
        int count = 0;
        int x_size = board.size();
        int y_size = board[0].size();
        
        for (int i=x-1; i<=x+1; ++i)
        {
            for (int j=y-1; j<=y+1; ++j)
            {
                if (i==x && j==y)
                    continue;
                if (i >= 0 && i < x_size && j >= 0 && j < y_size && board[i][j] == 'M')
                    ++count;
            }
        }
        return count;
    }
    void myDFS(vector<vector<char>>& board, int x, int y)
    {
        int x_size = board.size();
        int y_size = board[0].size();
        
        if (x < 0 || x >= x_size || y < 0 || y >= y_size || board[x][y] != 'E')
        {
            return;
        }
        else
        {
            int count = getMines(board, x, y);
            //cout<< count <<endl;
            if (count != 0)
            {
                board[x][y] = '0' + count;
            }
            else
            {
                board[x][y] = 'B';
                
                for (int i=x-1; i<=x+1; ++i)
                {
                    for (int j=y-1; j<=y+1; ++j)
                    {
                        if (!(i==x && j==y))
                            myDFS(board, i, j);
                    }
                }
            }
        }
        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int x = click[0];
        int y = click[1];
        
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        
        myDFS(board, x, y);
        return board;
    }
};
