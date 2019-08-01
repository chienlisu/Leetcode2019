class Solution {
public:
    int longestMountain(vector<int>& A) {
        bool before_peak = true; 
        int ans = 0;
        int up_count = 1; 
        int down_count = 0;
        
        for (int i=1; i<A.size(); ++i)
        {
            if (A[i] == A[i-1])
            {
                if (!before_peak)
                {
                    ans = max(ans, up_count+down_count);
                }
                before_peak = true;
                up_count = 1;
                down_count = 0;
            }
            else if (A[i] > A[i-1])
            {
                if (before_peak)
                {
                    ++up_count;
                }
                else
                {
                    ans = max(ans, up_count+down_count);
                    up_count = 1+1;
                    down_count = 0;
                    before_peak = true;
                }
            }
            else
            {
                if (before_peak)
                {
                    if (up_count != 1)
                    {
                        before_peak = false;
                        ++down_count;
                    }
                    else
                    {
                        up_count = 1;
                        down_count = 0;
                        before_peak = true;
                    }
                }
                else
                {
                    ++down_count;
                }
            }
        }
        
        if (!before_peak)
            ans = max(ans, up_count+down_count);
            
        return ans;
    }
};
