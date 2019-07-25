class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> ans(366,0);
        int cost1, cost7, cost30;
        int size = days.size();
        
        for (int i=0; i<size; ++i)
        {
            int curr = days[i];
            cost1 = costs[0] + (curr>=1? ans[curr-1] : 0);
            cost7 = costs[1] + (curr>=7? ans[curr-7] : 0);
            cost30= costs[2] + (curr>=30? ans[curr-30]: 0);
            ans[curr] = min(cost30, min(cost1, cost7));
            cout<< ans[curr]<<endl;
            int j = days[i];
            while (i+1<size && j<days[i+1])
            {
                ans[j] = ans[curr];
                ++j;
            }
        }
        return ans[days[size-1]];
    }
};
