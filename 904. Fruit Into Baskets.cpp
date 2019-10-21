class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // longest subsequence (including two different numbers)
        vector<int> fruits{tree[0],-1};
        vector<int> indexes{0,-1};
        int total = 1;
        int sum = 1;
        
        for (int i=1; i<tree.size(); ++i)
        {
            if (tree[i] == fruits[0])
            {
                ++total;
                indexes[0] = i;
            }
            else if (fruits[1] == -1 || tree[i] == fruits[1])
            {
                ++total;
                indexes[1] = i;
                if (fruits[1] == -1)
                {
                    fruits[1] = tree[i];
                }
            }
            else
            {
                // sum the current subsequence.
                sum = max(total, sum);
                if (tree[i-1] == fruits[0])
                {
                    total = i - indexes[1];
                    fruits[1] = tree[i];
                    indexes[1]= i;
                }
                else
                {
                    total = i - indexes[0];
                    fruits[0] = tree[i];
                    indexes[0]= i;
                }
            }
        }
        return max(sum, total);
    }
};
