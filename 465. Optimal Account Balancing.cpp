class Solution {
public:
    int backTracking(vector<int>& oweV, vector<int>& payV, int idx)
    {
        // all payV are handled
        if (idx == payV.size())
        {
            return 0;
        }
        
        // skip the pay that doesn't need owe to compensate.
        if (payV[idx] == 0)
        {
            return 0;
        }
        
        int ans;
        
        // best way: find a matched oweV[i], cancel with each other.
        for (int i=0; i<oweV.size(); ++i)
        {
            if (oweV[i] == payV[idx])
            {
                int temp = oweV[i];
                oweV[i] = 0;
                payV[idx] = 0;
                ans = 1 + backTracking(oweV, payV, idx+1);
                oweV[i] = temp;
                payV[idx] = temp;
                return ans;
            }
        }
        
        ans = INT_MAX;
        for (int i=0; i<oweV.size(); ++i)
        {
            // skip oweV[i] without owe.
            if (oweV[i] == 0)
                continue;
            
            int temp;
            // if pay > owe, reduce current pay, cancel owe => continue current (pay)idx
            if (payV[idx] > oweV[i])
            {
                temp = oweV[i];
                payV[idx] -= oweV[i];
                oweV[i] = 0;
                ans = min(ans, 1+ backTracking(oweV, payV, idx));
                payV[idx] += temp;
                oweV[i] = temp;
            }
            // if owe > pay, reduce the owe, cancel current pay => move to next (pay)idx
            else // already handle "==" above
            {
                temp = payV[idx];
                oweV[i] -= payV[idx];
                payV[idx] = 0;
                ans = min(ans, 1+ backTracking(oweV, payV, idx+1));
                oweV[i] += temp;
                payV[idx] = temp;
            }
        }
        return ans;
        
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> data;
        
        for(auto trans :transactions)
        {
            data[trans[0]] += trans[2];
            data[trans[1]] -= trans[2];
        }
        
        vector<int> oweV; //for owe person
        vector<int> payV; //for pay person
        
        for (auto i:data)
        {
            if (i.second > 0)
            {
                payV.push_back(i.second);
            }
            else if (i.second < 0)
            {
                oweV.push_back(-i.second);
            }
        }
        
        return backTracking(oweV, payV, 0);
    }
};
