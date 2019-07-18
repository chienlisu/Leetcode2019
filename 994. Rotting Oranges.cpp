class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int x_size = grid.size();
        int y_size = grid[0].size();
        
        vector<vector<int>> visited(x_size, vector<int>(y_size, 0));
        queue<vector<int>> myQue;
        
        for (int i=0; i<x_size; ++i)
        {
            for (int j=0; j<y_size; ++j)
            {
                if (grid[i][j] == 2)
                    myQue.push({i,j,0});
            }
        }
        
        int count = 0;

        while (!myQue.empty())
        {
            int x = myQue.front()[0];
            int y = myQue.front()[1];
            count = myQue.front()[2];
            myQue.pop();

            for (int i=x-1; i<=x+1; i= i+2)
            {
                if (i >=0 && i < x_size && grid[i][y] == 1)
                {
                    grid[i][y] = 2;
                    myQue.push({i,y,count+1});
                }
            }
            for (int j=y-1; j<=y+1; j= j+2)
            {
                if (j >=0 && j < y_size && grid[x][j] == 1)
                {
                    grid[x][j] = 2;
                    myQue.push({x,j,count+1});
                }
            }
        }
         
        for (int i=0; i<x_size; ++i)
        {
            for (int j=0; j<y_size; ++j)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return count;
    }
};
