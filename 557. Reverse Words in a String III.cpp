class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        
        for (int i=0; i<s.length(); ++i)
        {
            if (s[i] != ' ')
            {
                temp = s[i] + temp;
            }
            else
            {
                ans = ans + temp + ' ';
                temp = "";
            }
        }
        if (temp != "")
            ans = ans + temp;
        
        return ans;
    }
};
