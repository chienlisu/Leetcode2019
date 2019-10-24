class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        
        if (len == 0)
            return false;
        
        set<string> dict;
        for (auto i : wordDict)
        {
            dict.insert(i);
        }
        
        vector<bool> ans(len+1, false);
        ans[0] = true;
        
        for (int i=1; i<=len; ++i) //i: count 1~len
        {
            for (int j=i-1; j>=0; --j) //j: index 0~(i-1)
            {
                string curr = s.substr(j, i-j); //substr index j~i-1
                if (ans[j] == true && dict.find(curr) != dict.end())
                {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[len];
    }
};
