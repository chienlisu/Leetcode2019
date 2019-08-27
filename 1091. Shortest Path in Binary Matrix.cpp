class Solution {
public:   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        if (grid[0][0] == 1|| grid[size-1][size-1] == 1)
            return -1;
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<pair<int, int>> myQue;
        int count = 0;
        
        myQue.push({0,0});
        
        while (!myQue.empty())
        {
            ++count;
            queue<pair<int,int>> temp;
            while (!myQue.empty())
            {
                pair<int,int> curr = myQue.front();
                myQue.pop();
                int x = curr.first, y = curr.second;
                if (x == size-1 && y == size-1)
                    return count;
                
                if (visited[x][y])
                    continue;
                visited[x][y] = true;
                
                for (int i=x-1; i<=x+1; ++i)
                {
                    for (int j=y-1; j<=y+1; ++j)
                    {
                        if (!(x==i && y ==j) && i>=0 && i<=size-1 && j>=0 && j<=size-1)
                        {
                            if (grid[i][j] == 0)
                            {
                                temp.push({i,j});
                                //cout<<i<<","<<j<<endl;
                            }
                        }
                    }
                }
            }
            myQue = temp;
        }
        return -1;
    }
};
