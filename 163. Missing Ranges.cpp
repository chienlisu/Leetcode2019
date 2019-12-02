class Solution {
public:
    int findIdx(vector<int>& nums, int n, bool is_low)
    {
        int l=0, h=nums.size()-1;
        
        while (l + 1 < h)
        {
            int m = l + (h-l)/2;
            
            if (is_low)
            {
                if (nums[m] >= n)
                {
                    h = m;
                }
                else
                {
                    l = m+1;
                }
            }
            else
            {
                if (nums[m] > n)
                {
                    h = m-1;
                }
                else
                {
                    l = m;
                }
            }
        }
        
        if (is_low)
            return (nums[l] >= n? l: h);
        else
            return (nums[h] <= n? h: l);
        
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // no nums.
        if (nums.size() == 0)
        {
            if (lower == upper)
                return {to_string(lower)};
            else
                return {to_string(lower)+"->"+to_string(upper)};    
        }
        
        vector<string> ans;
        // find 1st idx >= lower
        int low = findIdx(nums, lower, true);
        // find last idx <= upper
        int up = findIdx(nums, upper, false);
        
        if (nums[low] != lower)
        {
            if (nums[low] == lower + 1)
                ans.push_back(to_string(lower));
            else
                ans.push_back(to_string(lower) + "->" + to_string(nums[low]-1));
        }
        
        for (int i=low+1; i<=up;  ++i)
        {
            if (nums[i] == nums[i-1] || nums[i] == nums[i-1]+1)
                continue;
            if (nums[i] == nums[i-1] + 2)
                ans.push_back(to_string(nums[i-1]+1));
            else
                ans.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
        }
        
        if (nums[up] != upper)
        {
            if (nums[up] == upper-1)
                ans.push_back(to_string(upper));
            else
                ans.push_back(to_string(nums[up]+1) + "->" + to_string(upper));
        }
        return ans;
    }
};
