class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        int left_idx=-1;
        char left = '-';
        
        int i=0;
        while (i < dominoes.length())
        {
            if (dominoes[i] == '.')
            {
                ++i;
                continue;
            }
            
            if (left_idx == -1 || left == 'L')
            {
                for (int j=left_idx+1; j<i;++j)
                    ans[j] = dominoes[i]=='R'? '.':'L';
            }
            else // left == 'R' 
            {
                for (int j=left_idx+1; j<i; ++j)
                    ans[j] = dominoes[i] == 'R'? 
                            'R': (i-j < j-left_idx? 'L': (i-j == j-left_idx? '.':'R'));
            
            }
            ans[i] = dominoes[i];
            left_idx = i;
            left = dominoes[i];
            ++i;
        }
        if (left_idx != -1 && left_idx < dominoes.length()-1)
        {
            for (int i=left_idx+1; i<dominoes.length(); ++i)
                ans[i] = left == 'R'? 'R':'.';
        }        
        return ans;
    }
};
