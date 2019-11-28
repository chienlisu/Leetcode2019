class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0)
        {
            if (n%26 == 0)
            {
                ans = 'Z' + ans;
                n = n-26;
            }
            else
            {
                char curr = (n%26)-1 + 'A';
                ans = curr + ans;
                n = n - n%26;
            }
            n=n/26;
        }
        return ans;
    }
};
