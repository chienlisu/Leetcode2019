class Solution {
public:
    int myFind(int i, vector<int>& parent)
    {
        if (parent[i] == -1)
            return i;
        parent[i] = myFind(parent[i], parent);
        return parent[i];
    }
    void myUnion(int i, int j, vector<int>& parent, vector<int>& rank)
    {
        if (rank[i] >= rank[j])
        {    
            parent[j] = i;
            if (rank[i] == rank[j])
                ++rank[j];
        }
        else
        {
            parent[i] = j;
        }
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b){return(a[2] <= b[2]);});
        
        vector<int> mySet(N+1,-1);
        vector<int> rank(N+1,0);
        
        int count = 0;
        int cost = 0;
        
        for (int i=0; i<connections.size(); ++i)
        {
            int a = myFind(connections[i][0], mySet);
            int b = myFind(connections[i][1], mySet);
        
            if (a!=b)
            {
                myUnion(a, b, mySet, rank);
                ++count;
                cost += connections[i][2];
            }
        }
        return ((count == N-1)? cost: (-1));
    }
};
