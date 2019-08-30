class Solution {
public:
    bool fail = false;
    void myDFS(int i, vector<vector<int>>& table, vector<int>& color, int curr)
    {
        if (fail)
            return;
        
        if (curr == -1)
        {
            if (color[i] == -1)
                color[i] = 0;
            else
                return;
        }
        else if (color[i] == -1)
            color[i] = curr;
        else if (color[i] == curr)
            return;
        else
        {
            fail = true;
            return;
        }
        
        for (int j=0; j<table[i].size(); ++j)
        {
            myDFS(table[i][j], table, color, 1-curr);
        }
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> table(N+1); // ignore index 0
        vector<int> color(N+1, -1);
        
        for (int i=0; i<dislikes.size(); ++i)
        {
            table[dislikes[i][0]].push_back(dislikes[i][1]);
            table[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for (int i=1; i<=N; ++i)
        {
            myDFS(i, table, color, -1);
            if (fail)
                return false;
        }
        return true;
    }
};
