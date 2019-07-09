class Solution {
public:
    double helper(double x, int n)
    {
        double res;
        if (n == 0)
        {
            return 1;
        }
        
        res = helper(x, n/2);
        res = res*res;
        
        if (n%2 == 1)
            res = res*x;
        
        return res;
    }
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        if (n > 0)
            return helper(x, n);
        else
        {
            double res = 1;
            if (n == INT_MIN)
            {
                res = x;
                ++n;
            }
            res = res*helper(x, -n);
            return (1/res);
        }
    }
};
