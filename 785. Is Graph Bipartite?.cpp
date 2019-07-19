class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        
        vector<int> group(size, 0);
        
        for (int i=0; i<size; ++i)
        {
            if (group[i] == 0) // not colored yet
            {
                group[i] = 1;
                stack<int> myStack;
                myStack.push(i);
                
                while (!myStack.empty())
                {
                    int curr = myStack.top();
                    myStack.pop();
                    
                    for (int j=0; j<graph[curr].size(); ++j)
                    {
                        if (group[graph[curr][j]] == 0)
                        {
                            group[graph[curr][j]] = group[curr] == 1? 2:1;
                            myStack.push(graph[curr][j]);
                        }
                        else if (group[graph[curr][j]] == group[curr])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
