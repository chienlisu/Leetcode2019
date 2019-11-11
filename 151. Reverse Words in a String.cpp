class Solution {
public:
    string reverseWords(string s) {
        
        if (s.length() == 0)
            return s;
        
        stringstream ss(s);
        string ans = "";
        string curr;
        ss >> ans;
        
        while (ss >> curr)
        {
            ans = curr + " " + ans;
        }
        
        return ans;
    }
};
