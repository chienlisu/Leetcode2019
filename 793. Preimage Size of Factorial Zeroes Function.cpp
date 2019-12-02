class Solution {
public:
    long getZeros(long x)
    {
        long ans = 0;
        while (x >= 5)
        {
            ans += (x/5);
            x = x/5;
        }
        return ans;
    }
    int preimageSizeFZF(int K) {
        if (K == 0)
            return 5;
        
        long l=K, h=5*(long)K;
        
        while (l <= h)
        {
            long med = l + (h-l)/2;
            long curr = getZeros(med);
            if (K == curr)
            {
                //cout<<med;
                return 5;
            }
            else if (K < curr)
                h = med-1;
            else
                l = med+1;
        }
        return 0;
    }
};
