class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int size = A.size();
        vector<int> sort_idx(size);
        vector<int> ans;
        
        for (int i=0; i<size; ++i)
            sort_idx[i] = i+1;
        
        // get sorted index (max to min)
        sort( sort_idx.begin(),sort_idx.end(),
              [&A](int i, int j) {return A[i-1] > A[j-1];});
        
        for (int i=0; i<size; ++i)
        {
            int flip = sort_idx[i];
            // get actual location of this index.
            for (int j=0; j<ans.size(); ++j)
            {
                if (flip <= ans[j])
                    flip = ans[j]+1 - flip;
            }
            // pancake sort to make the current largest go the rightmost.
            ans.push_back(flip);
            ans.push_back(size-i);
        }
        
        return ans;
    }
};
