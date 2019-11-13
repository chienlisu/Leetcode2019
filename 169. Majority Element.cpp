class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int count = 0;
        
        for (auto i:nums)
        {
            if (count == 0)
            {
                ans = i;
            }
            if (ans == i)
                ++count;
            else
                --count;
        }
        return ans;
    }
};
