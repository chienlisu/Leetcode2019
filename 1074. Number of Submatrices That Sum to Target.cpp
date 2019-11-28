class Solution {
public:
    void getResult(int& ans, vector<int>& data, int target)
    {
        unordered_map<int, int> dict;
        for (int i=0; i<data.size(); ++i)
        {
            //cout <<data[i] <<endl;
            if (data[i] == target)
            {
                ++ans;
            }
            
            if (dict.find(data[i]-target) != dict.end())
            {
                ans += dict[data[i]-target];
            }
            ++dict[data[i]];
            
        }
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        
        for (int i=0; i<col; ++i)
        {
            vector<int> data(row, 0); //sum of matrix[0][j]~matrix[i][j]
            for (int j=i; j<col; ++j)
            {
                int  sum = 0;
                for (int k=0; k<row; ++k)
                {
                    sum += matrix[k][j];
                    data[k] += sum;    
                }
                getResult(ans, data, target);
            }           
        }
        return ans;
    }
};
