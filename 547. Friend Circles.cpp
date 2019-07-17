class Solution {
public:
    int myDFS(vector<vector<int>>& M, int i)
    {
        int rtn = 0;
        for (int j=0; j<M[0].size(); ++j)
        {
            if (M[i][j] == 1)
            {
                rtn = 1;
                M[i][j] = 0;
                M[j][i] = 0;
                myDFS(M, j); // DFS to go through all friends (overwrite to 0).
            }
        }
        return rtn;
        
    }
    int findCircleNum(vector<vector<int>>& M) {
        
        int count = 0;
        
        for (int i=0; i<M.size(); ++i)
        {
            count += myDFS(M, i);
        }
        return count;
    }
};
