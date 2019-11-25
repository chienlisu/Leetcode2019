class Solution {
public:
    bool binarySearch(long l, long h, int n)
    {
        if (l > h)
            return false;
        
        long m = l + (h-l)/2;
        
        if (m*m == n)
            return true;
        else if (m*m > n)
            return binarySearch(l, m-1, n);
        else
            return binarySearch(m+1, h, n);
        
    }
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        
        return binarySearch(1, num, num);
    }
};
