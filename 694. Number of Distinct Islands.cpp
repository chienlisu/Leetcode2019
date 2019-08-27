class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int x_size = grid.size();
        if (x_size == 0) return 0;
        int y_size = grid[0].size();
        if (y_size == 0) return 0;
        
        vector<vector<int>> visited(x_size, vector<int>(y_size, false));
        set<set<int>> total;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        for (int r=0; r<x_size; ++r)
        {
            for (int c=0; c<y_size; ++c)
            {
                if (visited[r][c] || grid[r][c] == 0)
                    continue;
                
                queue<pair<int, int>> coord;
                coord.push({r,c});
                
                set<int> curr_set;
                curr_set.insert(0); // r,c
                
                while (!coord.empty())
                {
                    pair<int, int> curr = coord.front();
                    int x = curr.first;
                    int y = curr.second;
                    coord.pop();
                    if (visited[x][y] == true)
                        continue;
                    visited[x][y] = true;
                    curr_set.insert((x-r)*2*y_size+(y-c)); // to avoid mis judgement
                    
                    for (int k= 0; k< dir.size() ; ++k)
                    {
                        int i= x + dir[k].first;
                        int j = y + dir[k].second;
                        if (i>=0 && i <x_size && j>=0 && j<y_size)
                        {
                            if (!visited[i][j] && grid[i][j]==1)
                                coord.push({i,j});
                        }
                    }
                }
                total.insert(curr_set);
                for(auto k:curr_set)
                    cout<<k<<",";
                cout<<endl;
            }
        }
        return total.size();
    }
};
