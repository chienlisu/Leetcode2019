class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int total = 0;
        vector<vector<int>> jobs(difficulty.size(), vector<int>(2,0));
        
        for (int i=0; i<difficulty.size(); ++i)
        {
            jobs[i][0] = difficulty[i];
            jobs[i][1] = profit[i];
        }
        
        sort(jobs.begin(),jobs.end(), [](vector<int> a, vector<int> b){return a[1] > b[1];});
        
        for (int i=0; i<worker.size(); ++i)
        {
            for (int j=0; j<jobs.size(); ++j)
            {
                if (worker[i] >= jobs[j][0])
                {
                    total += jobs[j][1];
                    break;
                }
            }
        }
        return total;
    }
};
