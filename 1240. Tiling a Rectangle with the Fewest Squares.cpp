class Solution {
public:
    void dfs(int& ans, int curr, int height, vector<int>& width)
    {
        // not optimal
        if (curr >= ans)
            return;
        
        // all filled, finish!
        auto it = min_element(width.begin(),width.end());
        int low = *it;
        if (low == height)
        {
            ans = curr;
            return;
        }
        
        int s = it - width.begin();
        int e = s;
        
        while (e < width.size() && width[s] == width[e] && (e-s+1 + low <= height))
            ++e;
        --e; // colum s~e are with min height.
        
        // try all possible squares
        for (int i=e; i>=s; --i)
        {
            int size = i-s+1;
            for (int j=s; j<=i; ++j)
            {
                width[j] += size;
            }
            dfs(ans, curr+1, height, width);
            for (int j=s; j<=i; ++j)
            {
                width[j] -= size;
            }
        }
    }
    
    int tilingRectangle(int n, int m) {
        
        // all 1*1 squares
        if (n == 1 || m == 1)
            return max(m,n);
        
        // 1 m*m square
        if (n == m)
            return 1;
        
        // keep width states short
        if (n > m)
            return tilingRectangle(m,n);
        
        vector<int> width(n, 0);
        int ans = m*n; //worst case: all 1*1 squares
        dfs(ans, 0, m, width);
        return ans;
    }
};
