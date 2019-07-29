class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int size = nums.size();
        if (total & 1)
            return false;
        if (size == 0)
            return true;
        else if (size == 1)
            return false;
        
        total = total/2;  // as long as we can find subset of i=0~size-1 s.t. sum = total/2, we get ans = true.
        vector<vector<bool>> ans(size+1, vector<bool>(total+1, false)); // ans[i][j] subset of nums[index]=0~i-1 s.t. sum = j
        
        for (int i=0; i<=size; ++i)
            ans[i][0] = true;
        
        for (int i=1; i<=size; ++i)
        {
            for (int j=1; j<=total; ++j)
            {
                if (nums[i-1] > j) // if current element > current target sum. ans = previous ans. (current element is unused.)
                    ans[i][j] = ans[i-1][j];
                else
                    ans[i][j] = ans[i-1][j] || ans[i-1][j-nums[i-1]]; // current is not used || current is used.
            }
        }
        return ans[size][total];
    }
};
