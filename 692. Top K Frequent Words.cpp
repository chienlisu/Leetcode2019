class Solution {
public:
    struct comp
    {
        public:
        bool operator()(const pair<string, int>& a, const pair<string, int>& b)
        {
            return a.second != b.second ? (a.second > b.second) : (a.first < b.first); //minheap
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> dict;
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> topK;
        
        for (int i=0; i<words.size(); ++i)
        {
            if (dict.find(words[i]) == dict.end())
            {
                dict[words[i]] = 1;
            }
            else
            {
                ++dict[words[i]];
            }
        }

        int count = 0;
        for (auto i: dict)
        {
            topK.push(make_pair(i.first, i.second));
            if (topK.size() > k)
            {
                topK.pop();
            }
        }
        
        vector<string> ans(k);
        count = k-1;
        while (count >= 0)
        {
            ans[count] = topK.top().first;
            topK.pop();
            --count;
        }
        
        return ans;
    }
};
