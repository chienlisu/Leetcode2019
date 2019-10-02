class Solution {
public:
    int mySqrt(int x) {
        if (x < 1)
            return 0;
        else if (x < 4)
            return 1;
        
        int start = 0;
        int end = x/2;
        
        while (start + 1 < end)
        {
            int med = start + (end - start)/2;
            
            if (med < x/med)
            {
                start = med;
            }
            else if (med  > x/med)
            {
                end = med;
            }
            else // x is strill >= med*med
            {
                start = med;
            }
        }
        
        if (end <= x/end)
            return end;
        else
            return start;
    }
};
