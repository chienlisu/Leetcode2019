class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size =nums.size();
        
        if (size ==1)
            return nums[0];
        
        int ans = nums[0];
        int curr = ans;
        
        for (int i=1; i<size; ++i)
        {
            if (curr+nums[i] >= nums[i])
            {
                curr += nums[i];
            }
            else
            {
                curr = nums[i];
            }
            ans = max(curr, ans);
        }
        return ans;
    }
};
