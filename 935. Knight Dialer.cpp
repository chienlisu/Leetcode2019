class Solution {
public:
    int knightDialer(int N) {
        long ans[10][N]; //state,steps
        for (int i=0; i<=9; ++i)
            ans[i][0] = 1;
        
        for(int i=1; i<N; ++i)
        {
            ans[0][i] = (ans[4][i-1]+ans[6][i-1])%1000000007;
            ans[1][i] = (ans[6][i-1]+ans[8][i-1])%1000000007;
            ans[2][i] = (ans[7][i-1]+ans[9][i-1])%1000000007;
            ans[3][i] = ans[1][i];//(ans[4][i-1]+ans[8][i-1])%1000000007;
            ans[4][i] = (ans[0][i-1]+ans[3][i-1]+ans[9][i-1])%1000000007;
            ans[5][i] = 0;
            ans[6][i] = ans[4][i];//(ans[0][i-1]+ans[1][i-1]+ans[7][i-1])%1000000007;
            ans[7][i] = (ans[2][i-1]+ans[6][i-1])%1000000007;
            ans[8][i] = (ans[1][i-1]+ans[3][i-1])%1000000007;
            ans[9][i] = ans[7][i];//(ans[2][i-1]+ans[4][i-1])%1000000007;
        }
        
        long sum = 0;
        for (int i=0; i<=9; ++i)
            sum += ans[i][N-1];
        
        return (sum%1000000007); 
    }
};
