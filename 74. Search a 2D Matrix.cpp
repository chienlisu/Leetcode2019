class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int i_idx, int j_start, int j_end, int target)
    {
        int j_low=j_start, j_high=j_end;
        int j_med;
        while(j_low <= j_high)
        {
            j_med = j_low + (j_high-j_low)/2;
            if (matrix[i_idx][j_med] == target)
                return true;
            else if (matrix[i_idx][j_med] > target)
                j_high = j_med - 1;
            else
                j_low = j_med + 1;
        }
        return false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i_size = matrix.size();
        if (i_size == 0)
            return false;
        int j_size = matrix[0].size();
        if (j_size == 0)
            return false;
        
        int i_low=0, i_high=i_size-1;
        int j_low=0, j_high=j_size-1;
        int i_med = i_low + (i_high-i_low)/2;
        int j_med = j_low + (j_high-j_low)/2;
        
        while (i_low < i_high )
        {
            i_med = i_low + (i_high-i_low)/2;
            if (matrix[i_med][j_med] == target)
                return true;
            else if (matrix[i_med][j_med] > target)
                i_high = i_med - 1;
            else
                i_low = i_med + 1;
        }
        
        i_med = i_high < 0? i_low : (i_low > i_size-1 ? i_high : i_low);
        if (matrix[i_med][j_med] == target) //here i_low == i_high == i_med
            return true;
        else if (matrix[i_med][j_med] > target)
        {
            //search matrix[i_med-1][j_med]~matrix[i_med][j_med-1]
            if (i_med > 0 && matrix[i_med-1][j_size-1] == target)
                return true;
            else if (i_med > 0 && matrix[i_med-1][j_size-1] > target)
                return helper(matrix, i_med-1, j_med, j_size-1, target);
            else
                return helper(matrix, i_med, 0, j_med, target);
        }
        else
        {
            //search matrix[i_med][j_med+1]~matrix[i_med+1][j_med]
            if (matrix[i_med][j_size-1] == target)
                return true;
            else if (matrix[i_med][j_size-1] > target)
                return helper(matrix, i_med, j_med, j_size-1, target);
            else if (i_med < i_size-1)
            {
                return helper(matrix, i_med+1, 0, j_med, target);
            }
            else
            {    
                return false;
            }        
        }
    }
};
