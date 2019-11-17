class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;
        int currMax = 0;
        
        for (int i=0; i<A.size(); ++i)
        {
            ans = max(ans, currMax + A[i] - i);
            currMax = max(currMax, A[i] + i);
        }
        return ans;
    }
};
