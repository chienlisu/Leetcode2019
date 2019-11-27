class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for (auto i:t)
            ++t_map[i];
        
        unordered_map<char, int> s_map;
        int ans = INT_MAX; 
        string res = "";
        
        int left = 0;
        int right = 0;
        int matched = 0;
        
        while (right<s.length())
        {
            char curr = s[right];
            if (t_map.find(curr) != t_map.end())
            {
                if (s_map.find(curr) == s_map.end() || s_map[curr] == 0)
                {
                    s_map[curr] = 1;
                }
                else
                {
                    ++s_map[curr];
                }
                if (s_map[curr] == t_map[curr])
                {
                    ++matched;
                }
            }
            
            while (matched == t_map.size())
            {
                if (ans >= right-left+1)
                {
                    ans = right-left+1;
                    res = s.substr(left,right-left+1);
                }
                char temp = s[left];
                ++left;
                if(s_map.find(temp)!=s_map.end())
                {
                    --s_map[temp];
                    if (s_map[temp] < t_map[temp])
                    {
                        --matched;
                    }
                }
            }
            ++right;
        }
        return res;
    }
};
