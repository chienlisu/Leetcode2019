class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        
        vector<int> lastMin(arr.size()+1);
        lastMin[arr.size()] = INT_MAX; // trick: add last element as MAX 
        for (int i=arr.size()-1; i>=0; --i)
        {
            lastMin[i] = min(lastMin[i+1], arr[i]);    
        }
        
        int currMax = INT_MIN;
        for (int i=0; i<arr.size(); ++i)
        {
            currMax = max(currMax, arr[i]);
            if (currMax <= lastMin[i+1])
            {
                ++ans;
            }
        }
        return ans;
    }
};
