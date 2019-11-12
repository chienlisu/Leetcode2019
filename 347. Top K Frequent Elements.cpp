class Solution {
public:
    class comp{
      public:
        bool operator()(pair<int,int>& a, pair<int,int>& b)
        {
            return{a.second > b.second};
        }
        
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        
        for (auto i:nums)
        {
            if (dict.find(i) == dict.end())
                dict[i] = 1;
            else
                ++dict[i];
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> minHeap;    
        for (auto i:dict)
        {
            minHeap.push(pair<int,int>{i.first,i.second});
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        vector<int> ans;
        while (!minHeap.empty())
        {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return ans;
    }
};
