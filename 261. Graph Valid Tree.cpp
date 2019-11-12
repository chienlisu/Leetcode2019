class Solution {
public:
    // used to find parent (find)
    int findParent(vector<int>& parent, int i)
    {
        while (parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // init.
        vector<int> parent(n);
        for (int i=0; i<n; ++i)
            parent[i] = i;

        
        for (int i=0; i<edges.size(); ++i)
        {
            int first = findParent(parent, edges[i][0]);
            int second = findParent(parent, edges[i][1]);
            
            if (first != second)
            {
                parent[second] = first; // (union)
            }
            else
            {
                return false; // check if a circle haapens (not a valid tree)
            }
        }
        
        // check if only one set exists
        int par = findParent(parent, 0);
        for (int i=0; i<n; ++i)
        {
            if (par!= findParent(parent, i))   
                return false;
        }
        return true;
    }
};
