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
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(),logs.end());
        vector<int> parent(N, -1);
        vector<int> rank(N, 0);
        int count = 0; // need N-1 times union.
        
        for (int i=0; i<logs.size(); ++i)
        {
            int a = myFind(logs[i][1], parent);
            int b = myFind(logs[i][2], parent);
            
            if (a!=b)
            {
                ++count;
                myUnion(a, b, parent, rank);
            }
            if(count == N-1)
                return logs[i][0];
        }
        return -1;
    }
};
