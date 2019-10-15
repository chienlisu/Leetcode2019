class Solution {
public:
    int checkFirstList(vector<int>& A, vector<int>& B, bool firstStart)
    {
        int count = firstStart? 0 : 1;
        int model = firstStart? A[0] : B[0];
            
        for (int i=1; i< A.size(); ++i)
        {
            if (A[i] == model)
                continue;
            else if (B[i] == model)
                ++count;
            else
            {
                count = -1;
                break;
            }
        }
        
        if (count == -1)
        {
            return max(A.size(), B.size()) + 1;
        }
        else
        {
            return count;
        }
    }
    
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.size() == 0 || B.size() == 0)
            return 0;
        
        // could be better: if follow A[0] succeeds, don't have to check follow B[0]
        int ans1 = checkFirstList(A,B,true);
        int ans2 = checkFirstList(A,B,false);
        int ans3 = checkFirstList(B,A,true);
        int ans4 = checkFirstList(B,A,false);
        int ans = min(min(ans1,ans2), min(ans3,ans4));
        
        return (ans > A.size()? -1: ans);
    }
};
