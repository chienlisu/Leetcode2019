class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<int> dict;
        string key = "";
        
        for (int i=0; i<S.length(); ++i)
        {
            if (i == 0 || S[i] != S[i-1])
            {
                dict.push_back(1);
                key = key + S[i];
            }
            else
            {
                ++dict[dict.size()-1];
            }
        }
        
        int ans = 0;
        for (auto word: words)
        {
            string curr = "";
            vector<int> count = {};
            for (int i=0; i<word.length(); ++i)
            {
                if (i == 0 || word[i] != word[i-1])
                {
                    curr = curr + word[i];
                    count.push_back(1);
                }
                else
                {
                    ++count[count.size()-1];
                }
            }
            if (curr != key)
            {
                continue;
            }
            int i;
            for (i=0; i<count.size(); ++i)
            {
                if (count[i] > dict[i] || (count[i] != dict[i] && dict[i] <= 2))
                {
                    break;
                }
            }
            if (i == count.size())
            {
                ++ans;
            }
        }
        return ans;
    }
};
