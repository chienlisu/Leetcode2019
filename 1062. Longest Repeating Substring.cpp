class Solution {
public:
    bool findSubstring(string S, int len)
    {
        set<string> dict;
        for (int i=0; i<=S.length()-len; ++i)
        {
            string curr = S.substr(i, len);
            if (dict.find(curr) != dict.end())
                return true;
            else
                dict.insert(curr);
        }
        return false;
        
    }
    int longestRepeatingSubstring(string S) {
        int len = S.length();
        
        int l=1, h=len;
        
        while (l <= h)
        {
            int med = l + (h-l)/2;
             
            if (findSubstring(S, med) == false)
            {
                h = med - 1;
            }
            else
            {
                l = med + 1;
            }
        }
       
        return (l-1);
    }
};
