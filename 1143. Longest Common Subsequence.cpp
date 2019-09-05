class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        int ans[len1+1][len2+1];
        
        for (int i=0; i<=len1; ++i)
            ans[i][0] = 0;
        for (int i=0; i<=len2; ++i)
            ans[0][i] = 0;
        
        for (int i=1; i<=len1; ++i)
        {
            for (int j=1; j<=len2; ++j)
            {
                if (text1[i-1] == text2[j-1])
                {
                    ans[i][j] = max(ans[i-1][j-1]+1, max(ans[i][j-1], ans[i-1][j]));
                }
                else 
                {
                    ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
                }
            }
        }
        return ans[len1][len2];
    }
};
