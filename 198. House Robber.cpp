class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;
        else if (size == 1)
            return nums[0];
        else if (size == 2)
            return (nums[0] > nums[1]? nums[0] : nums[1]);
                        
        vector<int> max(size, 0);      
        
        max[0] = nums[0];
        max[1] = (nums[0] > nums[1]? nums[0] : nums[1]);
        
        for (int i=2; i<size; ++i)
        {
            if (max[i-2] + nums[i] > max[i-1])
                max[i] = max[i-2] + nums[i];
            else
                max[i] = max[i-1];
        }
        return max[size-1];
    }
};
