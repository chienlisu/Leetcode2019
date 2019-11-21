class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        if (W == 1)
            return true;
        if (size%W != 0)
            return false;
        
        map<int, int> dict;
        for (auto i: hand)
            ++dict[i];
        
        for (auto i: dict)
        {
            int curr = i.first;
            if (i.second == 0)
            {
                continue;
            }
            for (int j=curr; j< curr+W; ++j)
            {
                if (dict.find(j) == dict.end() || dict[j] < i.second)
                {
                    return false;
                }
                dict[j] -= i.second;
            }
            //dict[curr] = 0;
        }
        return true;
    }
};
