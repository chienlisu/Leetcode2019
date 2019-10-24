class Solution {
public:
    void backTracking(string& str, vector<vector<char>>& board, int i, int j, int curr, bool& matched)
    {
        if (matched == true)
        {
            return;
        }
        
        if (curr == str.length())
        {
            
            matched = true;
            return;
        }
        
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size())
        {
            return;
        }
        
        if (str[curr] == board[i][j])
        {
            board[i][j] = '*';
            backTracking(str, board, i-1, j, curr+1, matched);
            backTracking(str, board, i+1, j, curr+1, matched);
            backTracking(str, board, i, j-1, curr+1, matched);
            backTracking(str, board, i, j+1, curr+1, matched);
            board[i][j] = str[curr];
        }   
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0 || board[0].size() == 0)
            return {};
        
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        
        for (int k=0; k<words.size(); ++k)
        {
            string str = words[k];
            bool matched = false;
            for (int i=0; i<m; ++i)
            {
                for (int j=0; j<n; ++j)
                {
                    backTracking(str, board, i, j, 0, matched);             
                    if (matched)
                    {
                        break;
                    }
                }
                if (matched)
                {
                    break;
                }
            }
            if (matched)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};
