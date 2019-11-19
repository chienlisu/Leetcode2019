class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, int start, int end, int findLeft)
    {
        int l = start;
        int h = end;
        
        if (findLeft)
        {
            while (l + 1 < h)
            {
                int med = l + (h-l)/2;
            
                if (nums[med] < target)
                {
                    l = med + 1;
                }
                else
                {
                    h = med;
                }
            }
            if (nums[l] == target)
                return l;
            else if (nums[h] == target)
                return h;
            else
                return -1;
        }
        else
        {
            while (l + 1 < h)
            {
                int med = l + (h-l)/2;
            
                if (nums[med] <= target)
                {
                    l = med;
                }
                else
                {
                    h = med - 1;
                }
            }
            if (nums[h] == target)
                return h;
            else
                return l;
        }       
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return {-1,-1};
        }
        int left = BinarySearch(nums, target, 0, nums.size()-1, true);
        if (left == -1)
        {
            return {-1,-1}; // not found
        }
        int right = BinarySearch(nums, target, left, nums.size()-1, false);
        return {left, right};
    }
};
