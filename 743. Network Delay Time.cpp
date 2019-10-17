class Solution {
public:
    class comp
    {
        public:
            bool operator()(pair<int,int>& a, pair<int,int>& b)
            {
                return a.second > b.second; // minHeap
            }
    };
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        // init. dist/visited
        vector<int> dist(N+1, INT_MAX); // dist from K to node x
        vector<bool> visited(N+1, false);
        dist[K] = 0;
        
        // record edges of each node
        unordered_map<int, vector<pair<int,int>>> edges;
        {
            for (int i=0; i<times.size(); ++i)
            {
                edges[times[i][0]].push_back(pair<int,int>{times[i][1],times[i][2]});  
            }
        }
        
        // use priority queue to extract reachable edges in order (node,dist)
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> myQue;
        
        myQue.push(pair<int,int>{K, dist[K]});
        
        while (!myQue.empty())
        {   
            int node = myQue.top().first;
            int currDist = myQue.top().second;
            myQue.pop();
         
            if (visited[node] == true)
            {
                continue;
            }
            visited[node] = true;
            
            for (auto i: edges[node])
            {
                int nextNode = i.first;
                int nextDist = i.second;
                
                if (dist[nextNode] > currDist + nextDist)
                {
                    dist[nextNode] = currDist + nextDist;
                    myQue.push(pair<int,int>{nextNode, dist[nextNode]});
                }
            }
        }
        
        int ans = -1;
        for (int i=1; i<=N; ++i)
        {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX? -1:ans;
    }
};
