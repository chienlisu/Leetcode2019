class Solution {
public:
    unordered_map<int, set<string>> dict;
    
    bool check_neighbor(string x, string y)
    {
        int len = x.length();
        int i = 0;
        while (i < len && x[i] == y[i])
        {
            ++i;
        }
        // x, y diff only for 1 character.
        while (i < len && x[i] == y[i+1])
        {
            ++i;
        }
        
        return (i == len);
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        vector<vector<int>> dict(17); // word len = 1~16, empty for dict[0] 
        vector<int> dp(words.size(), 0);
        
        for (int i=0; i<words.size(); ++i)
        {
            dict[words[i].length()].push_back(i);
        }
        
        for(int len=1; len<16; ++len)
        {
            for (auto i: dict[len])
            {
                for (auto j: dict[len+1])
                {
                    if (check_neighbor(words[i],words[j]))
                    {
                        dp[j] = max(dp[j], dp[i]+1);   
                    }
                }
            }
        }
        
        int ans = *max_element(dp.begin(),dp.end()) + 1;
        
        return ans;
    }
};
