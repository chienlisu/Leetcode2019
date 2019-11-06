class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        if (n == 2)
            return 0;
        
        vector<int> primes = {2};
        int count = 1;
        
        for (int i=3; i<n; ++i)
        {
            for (int j=0; j<primes.size(); ++j)
            {
                if (i%primes[j] == 0)
                {
                    break;
                }
                else if(primes[j]*primes[j] > i)
                {
                    ++count;
                    primes.push_back(i);
                    break;
                }
            }
        }
        return count;
    }
};
