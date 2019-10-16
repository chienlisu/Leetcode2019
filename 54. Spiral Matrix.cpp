class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        if (m == 0)
            return {};
        int n = matrix[0].size();
        if (n == 0)
            return {};
        
        int size = 0;
        int circleCount = 0;
        vector<int> ans;
        
        while (size < min(m,n))
        {
            for (int i=circleCount; i<=n-1-circleCount; ++i)
                ans.push_back(matrix[circleCount][i]);
            
            if (m-size == 1)
            {
                break;
            }
            
            for (int i=circleCount+1; i<=m-1-circleCount; ++i)
                ans.push_back(matrix[i][n-1-circleCount]);
            
            if (n-size == 1)
            {
                break;
            }
            
            for (int i=n-1-circleCount-1; i>=circleCount; --i)
                ans.push_back(matrix[m-1-circleCount][i]);
            
            for (int i=m-1-circleCount-1; i>=circleCount+1; --i)
                ans.push_back(matrix[i][circleCount]);
            
            size = size + 2;
            ++circleCount;
        }
        return ans;
    }
};
