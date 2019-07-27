class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int size = books.size();
        vector<int> ans(size+1, 0);
        ans[0] = books[0][1];
        for (int i=1; i<size; ++i)
        {
            int this_start = i;
            int curr_height = books[i][1];
            int curr_weight = books[i][0];
            int temp = INT_MAX;
            while (this_start >=0 && curr_weight <= shelf_width)
            {
                if (this_start == 0)
                {
                    temp = min(temp, curr_height);
                    break;
                }    
                temp = min(temp, ans[this_start-1] + curr_height);
                curr_weight += books[this_start-1][0];
                curr_height = max(curr_height, books[this_start-1][1]);
                --this_start;
            }
            ans[i] = temp;
            cout<<ans[i]<<endl;
        }
        return ans[size-1];
    }
};
