class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<long>> ans(d+1, vector<long>(target+1, 0));
        for (int i=1; i<=f && i<=target; ++i)
            ans[1][i] = 1;
        
        for (int i=2; i<=d; ++i)
        {
            for (int j=1; j<=target; ++j)
            {
                int temp = 0;
                for (int k=1; k<=f && k<j; ++k)
                {
                    temp = (temp + ans[i-1][j-k])%1000000007;
                }
                ans[i][j] = temp;
                //cout<<i<<","<<j<<","<<temp<<endl;
            }
        }
        return ans[d][target];
    }
};
