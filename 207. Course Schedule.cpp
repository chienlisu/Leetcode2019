class Solution {
public:
    void dfs(bool& ans, int i, vector<vector<int>>& adj, vector<int>& visited)
    {
        // already find cycle.
        if (ans == false)
            return;
        
        // already finish lookup of this node.
        if (visited[i] == 2)
            return;
        
        // already traverse this node in the same lookup => cycle found
        if (visited[i] == 1)
        {
            ans = false;
            return;
        }
        
        // start visiting nodes via dfs
        visited[i] = 1;
        for (int j=0; j<adj[i].size(); ++j)
        {
            dfs(ans, adj[i][j], adj, visited);
        }
        
        // finish lookup of this node.
        visited[i] = 2;
        return;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i=0; i<prerequisites.size(); ++i)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0); //0: not visisted, 1:visiting, 2:visited
        
        bool ans = true;
        for (int i=0; i<numCourses; ++i)
        {
            if (visited[i] == 0)
            {
                dfs(ans, i, adj, visited);
            }
        }
        return ans;
    }
};
