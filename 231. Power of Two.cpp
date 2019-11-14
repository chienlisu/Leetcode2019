class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        
        int count = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                ++count;
            }
            if (count == 2)
            {
                return false;
            }
            n = n >> 1;
        }
        return true;
    }
};
