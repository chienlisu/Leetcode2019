class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        
        if (size == 0)
            return -1;
        else if(size == 1)
            return (target == nums[0]? 0: -1);
        
        int low = 0, high = size-1;
        int med;
        
        while (low <= high)
        {
            med = low + (high-low)/2;
            
            if (nums[med] == target)
                return med;
            else if (nums[med] > target)
                high = med-1;
            else
                low = med+1;
        }
        return -1;
    }
};
