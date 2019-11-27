class Solution {
public:
    int findSubstring(string S, int len, vector<int>& num)
    {
        set<long long> dict;
        long long curr = 0;
        long long mod = pow(2,32);
        long long rest=1;
        
        for (int i=0; i<len; ++i)
        {
            curr = (26*curr + num[i])%mod; // module to avoid overflow
            if (i != 0)
                rest = (26*rest)%mod;
        }
        
        dict.insert(curr);
        for (int i=1; i<=S.length()-len; ++i)
        {
            curr = ((curr- rest*num[i-1])*26 + num[i+len-1])%mod;
            if (dict.find(curr) == dict.end())
                dict.insert(curr);
            else
                return i;
        }
        return -1;
    }
    
    
    string longestDupSubstring(string S) {
        // char->int (to improve hash)
        int len = S.length();
        vector<int> num(len);
        for (int i=0; i<len; ++i)
            num[i] = (S[i]-'a');
        
        // binary search to get max duplicate substring len.
        int l =1, h = len; 
        while (l <= h)
        {
            int med = l + (h - l)/2;
            if (findSubstring(S, med, num) != -1)
            {
                l = med+1;
            }
            else
            {
                h = med-1;
            }
        }
        
        if (l == 1)
            return "";
        
        int idx = findSubstring(S, l-1, num);
        return S.substr(idx, l-1);
    }
};
