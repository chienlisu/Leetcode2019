class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        
        if (size <= 1)
            return true;
        
        vector<bool> res(size, false);
        res[0] = true;
        for (int i=1; i<size; ++i)
        {
            for (int j=i-1; j>=0; --j)
            {
                if (res[j] == true && i-j <= nums[j])
                {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[size-1];
    }
};
