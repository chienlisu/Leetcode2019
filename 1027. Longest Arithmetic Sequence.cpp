class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        map<pair<int,int>, int> diff;
        int ans = 0;
        int delta;
        
        for (int i=0; i<A.size(); ++i)
        {
            for (int j=0; j<i; ++j)
            {
                delta = A[i]-A[j]; 
                if (diff.find({j,delta}) == diff.end()) 
                    diff[{i,delta}] = 1;
                else
                    diff[{i,delta}] = diff[{j,delta}] + 1;
                
                //cout<<A[i]<<","<<delta<<","<<diff[{A[i],delta}]<<endl;
                ans = max(ans, diff[{i,delta}]);
            }
        }
        return ans + 1;
    }
};
