class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n+1,0);
        
        ans[1] = 1;
        
        for (int i=2; i<=n; ++i)
        {
            int j = 1;
            int temp = INT_MAX;
            while (j*j <= i)
            {
                temp = min(temp, ans[i-j*j]+1);
                ++j;
            }
            ans[i] = temp;
        }
        return ans[n];
    }
};
