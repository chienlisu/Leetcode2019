class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int size = hours.size();
        int new_hours[size];
        for (int i=0; i<size; ++i)
            new_hours[i] = hours[i] > 8? 1: -1;
        
        int prefixSum[size];
        prefixSum[0] = new_hours[0];
        for (int i=1; i<size; ++i)
            prefixSum[i] = prefixSum[i-1]+new_hours[i];

        int ans[size] = {0};
        for (int i=0; i<size; ++i)
        {
            if (prefixSum[i] > 0)
            {
                ans[i] = i+1;
            }
            else
            {
                for (int j=0; j<i; ++j)
                {
                    if (prefixSum[j] < prefixSum[i])
                    {
                        ans[i] = i-j;
                        break;
                    }
                }
            }
        }
        
        int res = 0;
        for (int i=0; i<size; ++i)
            res = ans[i] > res? ans[i] : res;
        
        return res;
    }
};
