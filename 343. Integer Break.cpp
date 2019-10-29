class Solution {
public:
    int integerBreak(int n) {
        vector<int> ans(59,0); //0~58
        
        ans[1] = 1;
        ans[2] = 2; //special
        ans[3] = 3; //special 
        ans[4] = 4; 
        
        
        for (int i=5; i<=58; ++i)
        {
            for (int j=1; j<=i/2; ++j)
            {
                ans[i] = max(ans[i], ans[j]*ans[i-j]);
            }
        }
        ans[2] = 1;
        ans[3] = 2;
        return ans[n];
    }
};
