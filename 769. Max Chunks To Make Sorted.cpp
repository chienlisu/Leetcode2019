class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        
        int idx = 0;
        int l = -1; //init
        int h = -1; //init
        int count = 0; 
        
        while (idx < arr.size())
        {
            if (count == 0)
            {
                l = idx;
                h = arr[idx];
                count = 1;
            }
            else
            {
                h = max(h,arr[idx]);
                ++count;
            }
            
            if (h-l+1 == count)
            {
                ++ans;
                count = 0;
            }
            
            ++idx;
        }
        
     
        return ans;
    }
};
