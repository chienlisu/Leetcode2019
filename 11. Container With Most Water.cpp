class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        
        if (size == 0)
            return 0;
        
        int start = 0;
        int end = size-1;
        int ans = 0;
        int curr;
        
        while (start < end)
        {
            ans = max(ans, min(height[start], height[end])* (end-start));
            
            if (height[start] < height[end])
            {    
                curr = start;
                ++start;
                while (start < end && height[start] < height[curr])
                {
                    ++start;
                }
            }
            else
            {
                curr = end;
                --end;
                while (start < end && height[end] < height[curr])
                {
                    --end;
                }
            }
        }
        return ans;
    }
};
