class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if ( len == 0 || s[0] == '0')
            return 0;
        if ( len == 1)
            return 1;
        
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i=1; i<len; ++i) //s[i]
        {
            int curr = stoi(s.substr(i-1,2));
            
            if (s[i] == '0') // single 0 is not a valid decode
            {
                if (s[i-1]-'0' > 2 || s[i-1]-'0' == 0)
                {
                    return 0;
                }
                else
                {
                    dp[i+1] = dp[i-1];
                }
            }
            else
            {
                if (curr < 10)
                    dp[i+1] = dp[i-1];
                else if (curr <= 26)
                    dp[i+1] = dp[i] + dp[i-1];
                else 
                    dp[i+1] = dp[i];
            }
        }
        return dp[len];
    }
};
