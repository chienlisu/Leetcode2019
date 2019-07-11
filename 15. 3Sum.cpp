class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int size = nums.size();
        if (size < 3)
            return {};
        sort(nums.begin(),nums.end());

        for (int i=0; i<size-2; ++i)
        {
            // avoid repeating
            if (i>0 && nums[i] == nums[i-1])
                continue;
            
            int x = i+1;
            int y = size-1;
            while (x < y)
            {
                if (nums[x]+nums[y]+nums[i] == 0)
                {
                    ans.insert({nums[i],nums[x],nums[y]});
                    ++x;
                    --y;
                    // avoid repeating
                    while (x < y && nums[x] == nums[x-1])
                        ++x;
                    while (x < y && nums[y] == nums[y+1])
                        --y;
                }
                else if (nums[x]+nums[y]+nums[i] < 0)
                {
                    ++x;
                }
                else
                {
                    --y;
                }
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
