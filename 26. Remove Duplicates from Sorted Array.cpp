class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int curr_idx = 0;
        
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] != nums[curr_idx])
            {
                ++curr_idx;
                nums[curr_idx] = nums[i];
            }
        }
        return (curr_idx+1);
    }
};
