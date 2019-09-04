class Solution {
public:
    int count = 0;
    int myRecursion(vector<int>& nums, int idx, int sum, int S)
    {
        if (idx == nums.size())
        {
            if (sum == S)
                return 1;
            else
                return 0;
        }
        return myRecursion(nums, idx+1, sum+nums[idx], S) + myRecursion(nums, idx+1, sum-nums[idx], S);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return myRecursion(nums, 0, 0, S);
    }
};
