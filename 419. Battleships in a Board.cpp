class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int x_size = board.size();
        if (x_size == 0)
            return 0;
        int y_size = board[0].size();
        if (y_size == 0)
            return 0;
        
        int count = 0;
        
        for(int i=0; i<x_size; ++i)
        {
            for (int j=0; j<y_size; ++j)
            {
                if (board[i][j] == 'X')
                {
                    ++count;
                
                    while (j+1 < y_size && board[i][j+1] == 'X')
                        ++j;
                
                    int temp = i+1;
                    while (temp < x_size && board[temp][j] == 'X')
                        board[temp++][j] = 'O'; //overwrite
                        
                }
            }
        }
        return count;
    }
};
