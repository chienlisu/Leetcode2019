class Solution {
public:
    bool myDFS(int i, vector<int>& color, vector<vector<int>>& graph)
    {
        if (color[i] != -1)
            return (color[i] == 1);
        
        color[i] = 0;
        for (int j=0; j<graph[i].size(); ++j)
        {
            if (color[graph[i][j]] == 1)
                continue;
            else if (color[graph[i][j]] == 0 || !myDFS(graph[i][j], color, graph))
                return false;
        }
        color[i] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int > ans;
        int size = graph.size();
        vector<int> color(size, -1); // -1: init, 0: after first visit, 1: saft node
        
        for (int i=0; i<size; ++i)
        {
            if (myDFS(i, color, graph))
                ans.push_back(i);
        }
        return ans;
    }
};
