class Solution {
public:
    // BFS + hashSet (visited)
    vector<pair<int,int>> dict = {{2,1}, {1,2}, {-1,2}, {-2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
    int minKnightMoves(int x, int y) {
        
        if (x == 0 && y == 0)
            return 0;
        
        queue<pair<int,int>> data;
        vector<vector<bool>> visited(601, vector<bool>(601,false));
        visited[0][0] = true;
        
        data.push({0,0});
        int ans = 0;
        
        while (!data.empty())
        {
            ++ans;
            int size = data.size();
            for (int i=0; i<size; ++i)
            {
                pair<int,int> curr = data.front();
                data.pop();
                
                for (int j=0; j<dict.size(); ++j)
                {
                    int next_x = curr.first + dict[j].first;
                    int next_y = curr.second + dict[j].second;
                    
                    if (next_x == x && next_y == y)
                        return ans;
                    
                    if (-300 <= next_x && next_x <= 300 &&
                         -300 <= next_y && next_y <= 300)
                    {
                        //cout << next_x << "," << next_y << endl;
                        if (visited[next_x+300][next_y+300])
                            continue;
                        visited[next_x+300][next_y+300] = true;
                        data.push({next_x,next_y});
                    }
                }
            }
        }
        return ans;
    }
};
