class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        if (len1 == 0)
            return len2;
        else if (len2 == 0)
            return len1;
        
        int ans[len1+1][len2+1];
        
        for (int i=0; i<=len1; ++i)
        {
            for (int j=0; j<=len2; ++j)
            {
                if (i == 0)
                    ans[i][j] = j;
                else if (j == 0)
                    ans[i][j] = i;
                else if (word1[i-1] == word2[j-1])
                {
                    ans[i][j] = ans[i-1][j-1];
                }
                else
                {
                    ans[i][j] = 1 + min( ans[i][j-1], ans[i-1][j]);
                }
            }
        }
/*        
        for (int i=0; i<=len1; ++i)
        {
            for (int j=0; j<=len2; ++j)
                cout << ans[i][j] << " ";
            cout <<endl;
        }
*/
        return ans[len1][len2];
    }
};
