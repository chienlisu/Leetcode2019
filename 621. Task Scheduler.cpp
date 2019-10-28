class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();
        
        vector<int> dict(26,0); // A~Z
        for (auto i: tasks)
        {
            ++dict[i-'A'];
        }
        sort(dict.begin(),dict.end());
        
        int maxCount = dict[25];
        int total = (maxCount-1)*(n+1);
        
        //find idle
        for (auto i:dict)
        {
            total -= min(i, maxCount-1);
            if (total < 0)
            {
                total = 0;
                break;
            }
        }
        int idle = total;
        
        // idle + tasks number = ans
        return (idle + tasks.size());
        
    }
};
