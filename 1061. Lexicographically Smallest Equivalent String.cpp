class Solution {
public:
    int myFind(int i, vector<int>& parent)
    {
        int temp = i;
        while (parent[temp] != -1)
        {
            temp = parent[temp];
        }

        return temp;
    }
    void myUnion(int i, int j, vector<int>& parent)
    {
        if (i < j)
            parent[j] = i;
        else
            parent[i] = j;
    }
    string smallestEquivalentString(string A, string B, string S) {
        int len = A.length();
        vector<int> parent(26, -1);
    
        for (int i=0; i<len; ++i)
        {
            int a = myFind(A[i]-'a', parent);
            int b = myFind(B[i]-'a', parent);
//cout<<a<<","<<b;
            if (a!=b)
                myUnion(a, b, parent);
        }
        
        for (int i=0; i<S.length(); ++i)
        {
            S[i] = ('a'+ myFind(S[i]-'a', parent));
        }
        return S;
    }
};
