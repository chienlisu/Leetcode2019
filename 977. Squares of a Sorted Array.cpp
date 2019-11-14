class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int idx = -1; // first positive
        for (int i=0; i<A.size(); ++i)
        {
            if (A[i] >= 0 && idx < 0)
            {
                idx = i;
            }
            A[i] = A[i]*A[i];
        }
        // if all numbers are negative
        if (idx == -1)
            idx = A.size();
        
        vector<int> ans={};
        int back = idx-1;
        int front = idx;
        while (back >=0 && front < A.size())
        {
            if (A[front] < A[back])
            {
                ans.push_back(A[front]);
                ++front;
            }
            else
            {
                ans.push_back(A[back]);
                --back;
            }
        }
        
        while (back >= 0)
        {
            ans.push_back(A[back]);
            --back;
        }
        while (front < A.size())
        {
            ans.push_back(A[front]);
            ++front;
        }
        
        return ans;
    }
};
