class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int ans = 0;
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 0 || visited[i][j] == true)
                {
                    continue;
                }
                
                stack<pair<int,int>> myStack;
                myStack.push(pair<int,int>{i,j});
                int total = 0;
                
                while (!myStack.empty())
                {
                    pair<int,int> curr = myStack.top();
                    myStack.pop();
                    if (visited[curr.first][curr.second] == true)
                    {
                        continue;
                    }
                    ++total;
                    visited[curr.first][curr.second] = true;
                    for (int k=0; k<4; ++k)
                    {
                        int next_x = curr.first+x[k];
                        int next_y = curr.second+y[k];
                        if(0 <= next_x && next_x < m &&
                           0 <= next_y && next_y < n &&
                           grid[next_x][next_y] == 1)
                        {
                            myStack.push(pair<int,int>{next_x,next_y});
                        }
                    }
                }
                ans = max(ans, total);    
            }
        }
        return ans;
    }
};
