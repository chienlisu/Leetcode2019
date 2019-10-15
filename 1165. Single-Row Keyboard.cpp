class Solution {
public:
    int calculateTime(string keyboard, string word) {
        
        if (word.length() == 0)
            return 0;
        
        vector<int> keyIdx(26);
        for (int i=0; i<keyboard.length(); ++i)
        {
            keyIdx[keyboard[i]-'a'] = i;
        }
        
        int curr = 0;
        int total = 0;
        for (int i=0; i<word.length(); ++i)
        {
            total += abs(keyIdx[word[i]-'a'] - curr);
            curr = keyIdx[word[i]-'a'];
        }
        return total;
    }
};
