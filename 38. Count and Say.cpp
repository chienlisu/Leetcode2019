class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        
        while (n > 1)
        {
            string temp = "";
            char curr = str[0];
            int count = 1;
            for(int i=1; i<str.length(); ++i)
            {
                if (curr == str[i])
                {
                    ++count;
                }
                else
                {
                    temp = temp + (to_string(count) + curr);
                    curr = str[i];
                    count = 1;
                }
            }
            temp = temp + (to_string(count) + curr); // the last one
            
            str = temp;
            --n;
        }
        return str;
    }
};
