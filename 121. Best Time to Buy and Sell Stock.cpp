class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int size = prices.size();
        int count = 0;
        
        for (int i=1; i<size; ++i)
        {
            count += (prices[i]-prices[i-1]);
            if (count <= 0)
                count = 0;
            
            if (count > max)
                max = count;
        }
        return max;
    }
};
