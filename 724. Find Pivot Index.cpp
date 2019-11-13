class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len == 1)
            return 0;
        
        int sum = 0;
        for (auto i:nums)
            sum += i;
        
        int sub = 0;
        for (int i=0; i<len; ++i)
        {
            if (sub == sum-sub-nums[i])
                return i;
            
            sub += nums[i];
        }
        return -1;
    }
};
