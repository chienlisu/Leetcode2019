class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<pair<int,int>>& dir, int row, int col)
    {
        if (visited[row][col])
            return;
        
        visited[row][col] = true;
        
        for (auto i: dir)
        {
            int x = row + i.first;
            int y = col + i.second;
            
            if (x >=0 && x < matrix.size() && y >=0 && y < matrix[0].size())
            {
                if (matrix[x][y] >= matrix[row][col])
                    dfs(matrix, visited, dir, x, y);
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        
        int m = matrix.size(), n = matrix[0].size();
        
        
        vector<vector<bool>> toPacific(m, vector<bool>(n, false));
        vector<vector<bool>> toAtlantic(m, vector<bool>(n, false));
        
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        // traverse from left/right edge to center 
        for (int i=0; i<m; ++i)
        {
            dfs(matrix, toPacific, dir, i, 0);
            dfs(matrix, toAtlantic, dir, i, n-1);
        }
        
        // traverse from upper/lower edge to center
        for (int i=0; i<n; ++i)
        {
            dfs(matrix, toPacific, dir, 0, i);
            dfs(matrix, toAtlantic, dir, m-1, i);
        }
        
        // check answer
        vector<vector<int>> ans;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (toPacific[i][j] && toAtlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
