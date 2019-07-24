class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
     
        int size = intervals.size();
        if (size <=1)
            return size;
        
        vector<int> start(size);
        vector<int> end(size);
        
        for (int i=0; i<size; ++i)
        {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int res = 0;
        int j = 0;
        
        for (int i=0; i<size; ++i)
        {
            while (start[i] >= end[j])
                ++j;
            
            res = max(i-j+1, res);
        }
        return res;
    }
};
