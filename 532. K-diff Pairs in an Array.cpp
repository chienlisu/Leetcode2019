class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        
        if (k < 0)
            return 0;
        
        int count = 0;
        
        if (k == 0)
        {
            unordered_map<int, int> dict;
            for (int i=0; i<nums.size(); ++i)
            {
                if (dict.find(nums[i]) == dict.end())
                {
                    dict[nums[i]] = 1;
                }
                else
                {
                    ++dict[nums[i]];
                }
            }
            for (auto i: dict)
            {
                if (i.second > 1)
                {
                    ++count;
                }
            }
        }
        else
        {
            set<int> dict;
            for (int i=0; i<nums.size(); ++i)
            {
                dict.insert(nums[i]);
            }
            for (auto i: dict)
            {
                int curr = i;
                if (dict.find(k+curr) != dict.end())
                {
                    ++count;
                }
            }
        }
        return count;
    }
};
