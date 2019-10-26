class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        if (size == 0)
            return 0;
        
        vector<vector<int>> minCost(size, vector<int>(3,INT_MAX));
        
        minCost[0][0] = costs[0][0];
        minCost[0][1] = costs[0][1];
        minCost[0][2] = costs[0][2];
        
        for (int i=1; i<size; ++i)
        {
            minCost[i][0] = costs[i][0] + min(minCost[i-1][1], minCost[i-1][2]);
            minCost[i][1] = costs[i][1] + min(minCost[i-1][0], minCost[i-1][2]);
            minCost[i][2] = costs[i][2] + min(minCost[i-1][0], minCost[i-1][1]);
        }
        
        return min(min(minCost[size-1][0], minCost[size-1][1]), minCost[size-1][2]);
    }
};
