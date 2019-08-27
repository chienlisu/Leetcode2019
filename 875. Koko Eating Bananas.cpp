class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        sort(piles.begin(), piles.end());
        
        int size = piles.size();
        int l = 1, h = 1000000000;

        while (l < h)
        {
            int m = l + (h-l)/2;
            int total = 0;
            
            for (int i=0; i<size; ++i)
            {
                total += (piles[i]+m-1)/m;
            }
            
            if (total > H)
                l = m+1;
            else
                h = m;
        }
        return l;
    }
};
