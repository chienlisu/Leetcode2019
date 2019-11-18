class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        
        vector<vector<int>> ans;
        for(auto word: words)
        {            
            if (text.length() < word.length())
                continue;
            for(int i=0; i<=text.length()-word.length();++i)
            {
                string temp = text.substr(i, word.length());
                if (temp == word)
                {
                    cout <<"get:" << i <<endl;
                    ans.push_back({i, i+word.length()-1});
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
