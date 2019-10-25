class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        bool neg = false;
        int i=0, len = str.length();
        
        // handle first whitespaces
        while (i < len)
        {
            if (str[i] == ' ')
            {
                ++i;
            }
            else 
            {
                break;
            }
        }
        
        // handle neg/pos
        if (str[i] == '-' || str[i] == '+')
        {
            neg = (str[i] == '-');
            ++i;
        }
        
        while (i < len)
        {
            // end number when reaching whiltespace/other characters
            if (str[i] == ' ' || str[i] - '0' < 0 || str[i] - '0' > 9)
            {
                break;
            }
            if (str[i] == '.')
            {
                break;
            }
                
            ans = 10*ans + (str[i]-'0');
            ++i;
            
            // handle overflow
            if (neg == false && ans > INT_MAX)
            {
                return INT_MAX;
            }
            else if (neg == true && ((-1)*ans) < INT_MIN )
            {
                return INT_MIN;
            }
        }
        return neg? ((-1)*ans): ans;
    }
};
