class Solution {
public:
    int shortestWay(string source, string target) {
        int len_s = source.length();
        int len_t = target.length();
        int count = 0;
        
        int i=0;
        
        while (i < len_t)
        {
            int j=0;
            int temp = i;
            while (j < len_s)
            {
                if (target[i] == source[j])
                {
                    ++i;
                }
                ++j;
            }
            ++count;
            
            if (temp == i)
                return (-1);
        }
        return count;
    }
};
