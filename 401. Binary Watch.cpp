class Solution {
public:
    int getBits(int val)
    {
        int ans = 0;
        while (val != 0)
        {
            if (val&1)
                ++ans;
            
            val = val >> 1;
        }
        return ans;
    }
    
    vector<string> readBinaryWatch(int num) {        
        if (num == 0)
            return {"0:00"};
        
        vector<int> hourBits(12, 0);
        vector<int> minBits(60,0);
        for (int i=0; i<=11; ++i)
        {
            hourBits[i] = getBits(i);
            minBits[i] = hourBits[i];
        }
        for (int i=12; i<=59; ++i)
        {
            minBits[i] = getBits(i);
        }
        
        vector<string> ans;
        
        for(int hour=0; hour<=11; ++hour)
        {
            for (int mins=0; mins<=59; ++mins)
            {
                if (hourBits[hour] + minBits[mins] == num)
                {
                    string temp = to_string(hour)+":"+ (mins <= 9? "0":"") + to_string(mins);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
