class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        char curr = chars[0];
        int count = 1;
        int idx = 0;
        chars.push_back(127); // trick: to handle tail
        
        for (int i=1; i<chars.size(); ++i)
        {
            if (chars[i] != curr)
            {
                chars[idx++] = curr;
                if (count > 1)
                {
                    string temp = to_string(count);
                    for (auto j: temp)
                        chars[idx++] = j;
                }                
                curr = chars[i];
                count = 1;
            }
            else
            {
                ++count;
            }
        }
        return idx;     
    }
};
