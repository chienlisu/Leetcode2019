class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        
        if (len2 == 0)
            return 0;
        if (len1 < len2)
            return -1;
        
        for (int i=0; i<=len1-len2; ++i)
        {
            if (needle == haystack.substr(i, len2))
                return i;
        }
        return -1;
    }
};
