class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search space reduction methond
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        int row =  matrix.size()-1;
        int col = 0;
        
        while ( col <= matrix[0].size()-1 && row >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                --row;
            else
                ++col;
        }
        return false;
    }
};
