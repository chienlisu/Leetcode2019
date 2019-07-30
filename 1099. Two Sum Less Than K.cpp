class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int ans = -1;
        int i=0, j=A.size()-1;
        
        sort(A.begin(),A.end());
        
        while (i < j)
        {
            int temp = A[i]+A[j];
            if (temp >= K)
            {
                --j;
            }
            else
            {
                ++i;
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
