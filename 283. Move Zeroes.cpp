class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int last_non_zero_idx = -1;
        
        for (int i=0; i<size; ++i)
        {
            if (nums[i] != 0)
            {
                ++last_non_zero_idx;
                swap(nums[last_non_zero_idx], nums[i]);
            }
        }
        return;
    }
};
