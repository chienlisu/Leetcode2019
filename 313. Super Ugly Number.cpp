class Solution {
public:
    int getMin(vector<int>&x)
    {
        int ans = INT_MAX;
        for (int i=0; i<x.size(); ++i)
        {
            if (ans > x[i])
                ans = x[i];
        }
        return ans;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    
        int size = primes.size();
        vector<int> ans(n);
        vector<int> next(size); // next candidates
        vector<int> to_multiply(size, 0); // record the numbers for next multiply of that prime
        
        ans[0] = 1;
        
        for (int i=0; i<size; ++i)
            next[i] = primes[i];
        
        int count = 1;
        int idx;
        while (count < n)
        {
            int temp = getMin(next);
            ans[count] = temp;
            ++count;
            cout << temp << ", ";
            
            for (int i=0; i<size; ++i)
            {
                if (temp == next[i])
                to_multiply[i]++;
                next[i] = ans[to_multiply[i]]*primes[i];
            }
        }
        return ans[n-1];
    }
}
