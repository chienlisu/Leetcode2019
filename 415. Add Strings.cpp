class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        
        if (len1 < len2)
        {
            string temp(len2-len1,'0');
            num1 = temp + num1;
        }
        else if (len2 < len1)
        {
            string temp(len1-len2,'0');
            num2 = temp + num2;
        }
        
        string ans = "";
        bool add=false;
        for (int i=num1.length()-1; i>=0; --i)
        {
            int curr = (num1[i]-'0') + (num2[i]-'0') + (add? 1:0); 
            add = curr >= 10? true:false;
            char c = add? ('0' + curr - 10): ('0'+curr);
            ans = c + ans;
        }
        if (add)
            ans = '1'+ans;
        
        return ans;
    }
};
