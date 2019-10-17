class Solution {
public:
    bool confusingNumber(int N) {
        
        vector<int> mapping = {0,1,-1,-1,-1,-1,9,-1,8,6}; // confusing number for 0-9
        int ans = 0;
        int temp = N;
        
        while (temp)
        {
            int curr = mapping[temp%10];
            if (curr == -1)
                return false;
            
            ans = 10*ans + curr;
            temp = temp/10;
        }
        return (N != ans);
    }
};
