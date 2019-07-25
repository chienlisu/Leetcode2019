class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curr_sum = 0;
        int total_sum = 0;
        
        for (int i=0; i<gas.size(); ++i)
        {
            if (curr_sum < 0)
            {
                curr_sum = gas[i] - cost[i];
                start = i;
            }
            else
                curr_sum += (gas[i]-cost[i]);
            
            total_sum += (gas[i]-cost[i]);
        }
        return (total_sum >=0? start:-1);
    }
};
