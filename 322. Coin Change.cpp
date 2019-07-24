class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0)
            return 0;
        else if (amount < 0 || coins.size() == 0)
            return -1;
        
        sort(coins.begin(), coins.end());
        int num = coins.size();
        vector<int> res(amount+1, -1);
        res[0] = 0;
        
        for (int i=0; i<=amount; ++i)
        {
            int temp = INT_MAX;
            for (int j=0; j<num; ++j)
            {
                if (i == coins[j])
                    temp = 1;
                else if(i < coins[j])
                    break;
                else
                {
                    if(res[i-coins[j]] != -1)
                    {
                        temp = min(temp, res[i-coins[j]]+1 );
                    }
                }
            }
            res[i] = (temp == INT_MAX)? (-1): temp;
        }
        return res[amount];
    }
};
