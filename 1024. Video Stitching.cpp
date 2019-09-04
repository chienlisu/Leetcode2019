class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        
        int idx = 0;
        int curr = 0;
        int temp = 0;
        int count = 0;
        
        while (idx < clips.size())
        {
            while (idx<clips.size() && clips[idx][0] <= curr)
            {
                temp = max(temp, clips[idx][1]);
                ++idx;
            }

            if (temp <= curr)
                return -1;
            curr = temp;
            ++count;
            if (curr >= T)
                return count;
        }
        return (-1);
    }
};
