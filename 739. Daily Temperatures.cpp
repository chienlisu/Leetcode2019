class Solution {
public:
    class comp
    {
        public:
            bool operator()(pair<int,int>& a , pair<int,int>& b)
            {
                return a.first > b.first;
            }
    };
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        if (size == 0)
        {
            return {};
        }
        else if (size == 1)
        {
            return {0};
        }
        
// optimize: use stack rather than heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> minHeap;
        vector<int> ans(size, 0);
        
        for (int i=0; i<size; ++i)
        {
            if (minHeap.empty())
            {
                minHeap.push(pair<int,int>{T[i],i});
                continue;
            }
            
            pair<int,int> curr = minHeap.top();

            while (curr.first < T[i])
            {
                ans[curr.second] = i - curr.second;
                minHeap.pop();

                if (!minHeap.empty())
                {
                    curr = minHeap.top();
                }
                else
                {
                    break;
                }
            }
            minHeap.push(pair<int,int>{T[i],i});                     
        }
        return ans;
    }
};
