class Solution {
public:
    //LCS DP
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        if (sizeA == 0 || sizeB == 0)
            return 0;
        
        int ans[sizeA+1][sizeB+1];
        
        for (int i=0; i<=sizeA; ++i)
        {
            for (int j=0; j<=sizeB; ++j)
            {
                if (i==0 || j==0)
                {
                    ans[i][j] = 0;
                }
                else if (A[i-1] == B[j-1])
                {
                    ans[i][j] = 1 + ans[i-1][j-1];
                }
                else
                {
                    ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
                }
            }
        }
        return ans[sizeA][sizeB];
    }
};
