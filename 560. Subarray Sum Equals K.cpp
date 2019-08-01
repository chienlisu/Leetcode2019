class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> myMap; //first: sum of the first k index, second: count of occurance of this sum
        int sum = 0;
        myMap[0] = 0;
        
        for (int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];
            
            if (sum == k)
            {
                ans += myMap[sum];
                ans += 1; // current
            }
            else if (myMap[sum-k] != 0)
            {
                ans += myMap[sum-k];    
            }
            ++myMap[sum];
        }
        return ans;
    }
};
