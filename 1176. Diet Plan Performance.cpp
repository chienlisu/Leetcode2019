class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int size = calories.size();
        int idx = 0;
        int total = 0;
        int ans = 0;
        
        for (idx = 0; idx<k; ++idx)
            total += calories[idx];
        ans += (total < lower? -1: (total > upper? 1: 0));
        
        while (idx < size)
        {
            total += calories[idx];
            total -= calories[idx-k];
            ans += (total < lower? -1: (total > upper? 1: 0));
            
            ++idx;
        }
        return ans;
    }
};
