class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int size = nums.size();
        
        if (size <=1)
            return;

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        // to avoid continuous repeating values,
        //for small:   s <- ss
        //for large:   ll <- l
        
        int j = 0;
        int i = ((size-1)%2==0)? (size-1): (size-2);
        for(; i>=0; i=i-2)
        {
            nums[i] = temp[j];
            ++j;
        }
        
        i = ((size-1)%2==0)? (size-2): (size-1);
        while (j < size)
        {
            nums[i] = temp[j];
            i = i-2;
            ++j;
        }
        return;
    }
};
