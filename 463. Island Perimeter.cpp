class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        int ans = 0;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ans +=4;
                    for (int k=0; k<4; ++k)
                    {
                        if (i+x[k] >=0 && i+x[k]<m && 
                            j+y[k]>=0 && j+y[k]<n &&
                            grid[i+x[k]][j+y[k]] == 1)
                        {
                            --ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
