class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0, curr = 0;
        int len = A.size();
        stack<pair<int, int>> myStack; //(value, count)
        
        for (int i=0; i<len; ++i)
        {
            int count = 1;
            while (!myStack.empty() && myStack.top().first >= A[i])
            {
                pair<int,int> out = myStack.top();
                myStack.pop();
                count += out.second;
                curr -= out.first*out.second;
            }
            
            myStack.push(pair<int,int>(A[i], count));
            curr += A[i]*count;
            ans += curr;
            ans %= 1000000007;
        }
        return ans;
    }
};
