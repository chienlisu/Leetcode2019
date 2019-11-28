class Solution {
public:
    class comp{
        public:
        bool operator()(pair<int,int>& a, pair<int,int>& b)
        {
            return a.first < b.first || (a.first == b.first && a.second < b.second); // drop first then pick-up
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<pair<int,int>> arr(2*trips.size());
        for (int i=0; i<trips.size(); ++ i)
        {
            arr[2*i].first = trips[i][1];
            arr[2*i].second = trips[i][0];
            arr[2*i+1].first = trips[i][2];
            arr[2*i+1].second = -trips[i][0];
        }
        sort(arr.begin(), arr.end(), comp());
        
        int curr = 0; 
        
        for (auto x:arr)
        {
            curr += x.second;
            if (curr > capacity)
                return false;
        }
        return true;
    }
};
