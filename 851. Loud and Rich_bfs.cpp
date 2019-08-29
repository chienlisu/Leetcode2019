class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vector<vector<int>> more(N);
        
        for (int i=0; i<richer.size(); ++i)
        {
            more[richer[i][1]].push_back(richer[i][0]);
        }
        
        vector<int> ans(N);
        for (int i=0; i<N; ++i)
            ans[i] = i;  // init.
        
        for (int i=0; i<N; ++i)
        {
            int minQuiet = quiet[i];
            vector<bool> visited(N, false);
            queue<int> myQue;
            for (int j=0; j<more[i].size(); ++j)
                myQue.push(more[i][j]);
            
            while (!myQue.empty())
            {
                int curr = myQue.front();
                myQue.pop();
                
                if (visited[curr])
                    continue;
                visited[curr] = true;
                
                if (quiet[curr] < minQuiet)
                {   
                    ans[i] = curr;
                    minQuiet = quiet[curr];
                }
                
                for (int j=0; j<more[curr].size(); ++j)
                    myQue.push(more[curr][j]);              
            }
        }
        return ans;
    }
};
