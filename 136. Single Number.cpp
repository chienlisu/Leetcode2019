class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, size = nums.size();
        int rtn = 0;
        for(i=0;i<size;i++)
        {
            rtn ^= nums[i];
        }
        return rtn;
    }
};
