class Solution {
public:
    class comp{
        public:
            bool operator()(vector<int>&a, vector<int>& b)
            {
                // trick: for equal height, put large width ahead (for doing longest increasing subsequence)
                return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
            }        
    };
    
    int LIS(vector<vector<int>>& arr)
    {
        vector<int> ans = {arr[0][1]};
        
        for (int i=1; i<arr.size(); ++i)
        {
            int curr = arr[i][1];
            int idx = lower_bound(ans.begin(), ans.end(), curr) - ans.begin();
            
            if (idx == ans.size())
            {
                ans.push_back(curr);
            }
            else
            {
                ans[idx] = curr;
            }
        }
        return ans.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if (size <= 1)
            return size;
        
        // sort height, and trick on sorting weight
        sort(envelopes.begin(), envelopes.end(), comp());
        
        // equivalent to "longest increasing subsequences" problem
        return LIS(envelopes);
    }
};
