class Solution {
public:
    bool isConfusing(int N)
    {
        int temp = N;
        int ans = 0;
        vector<int> mapping = {0,1,-1,-1,-1,-1,9,-1,8,6};
        
        while (temp)
        {
            int curr = mapping[temp%10];
            if (curr == -1)
                return false;
            ans = 10*ans + curr;
            temp = temp/10;
        }
        return (ans != N);
    }
    
    void dfs(int N, long curr, vector<int>& num, int& total)
    {
        if (curr > N)
            return;
        
        if (isConfusing(curr) == true)
            ++total;
        
        for (auto i: num)
        {
            long temp = 10*curr + i;
            dfs(N, temp, num, total);
        }
    }
        
    int confusingNumberII(int N) {
        vector<int> num = {0,1,6,8,9};
        int ans = 0;
        
        for (auto i:num)
        {
            if (i != 0)
                dfs(N, i, num, ans);
        }
        return ans;
    }
};
