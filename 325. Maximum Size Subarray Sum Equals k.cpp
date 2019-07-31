class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> myMap; // sum, sub-array length (count 0~i)
        int ans = 0;
        
        myMap[0] = 0;
        
        for (int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];
            
            if (sum == k)
            {
                ans = max(ans, i+1);
            }
            else if (myMap[sum-k] != 0)
            {
                ans = max(ans, i-myMap[sum-k]+1);
            }
            
            if (myMap[sum] == 0)
                myMap[sum] = i+1;
        }
        return ans;
    }
};
