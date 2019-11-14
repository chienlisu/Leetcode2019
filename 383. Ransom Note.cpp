class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // check if ransomNote is substr of magazine
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        if (len1 == 0)
            return true;
        if (len2 < len1)
            return false;
        
        vector<int> dict(26,0);
        for (auto i:magazine)
        {
            ++dict[i-'a'];
        }
        
        for (auto i:ransomNote)
        {
            --dict[i-'a'];
            if (dict[i-'a'] < 0)
                return false;
        }
        return true;
    }
};
