class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<string, int>>> myMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         myMap[key].push_back(pair<string,int>(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& curr = myMap[key]; // note: use reference to save time
        int l = 0;
        int h = curr.size()-1;
        
        if (h<0 || timestamp < curr[0].second)
            return "";
        
        while (l<h)
        {
            int m = l + (h-l)/2;
            if (timestamp >= curr[m].second)
                l = m+1;
            else
                h = m-1;
        }
        return (timestamp >= curr[l].second? curr[l].first : curr[l-1].first );
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
