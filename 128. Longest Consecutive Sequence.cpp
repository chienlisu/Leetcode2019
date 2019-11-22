class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> data;
        for (auto i:nums)
            data.insert(i);
        
        int ans = 0;
        int count;
        for (auto i:nums)
        {
            // not the head of this sequence, must not be answer.
            if (data.find(i-1) != data.end())
            {
                continue;
            }
            count = 1;
            int curr =i;
            while (data.find(curr+1) != data.end())
            {
                ++curr;
                ++count;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
