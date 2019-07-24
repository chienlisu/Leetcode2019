class Solution {
public:
    static bool mySort(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        
        if (size == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), mySort);
        
        int curr_end = intervals[0][1];
        int count = 0;
        
        for (int i=1; i<size; ++i)
        {
            if (intervals[i][0] < curr_end)
            {
                ++count;
            }
            else
            {
                curr_end = intervals[i][1];
            }
        }
        return count;
    }
};
