class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> dict; // record rest numbers of i
        unordered_map<int, int> tail; // record chains that ends before i (i.e. i can add to the chain)
        
        for (auto i:nums)
            ++dict[i];
        
        for (auto i: nums)
        {
            if (dict[i] == 0) // no rest of i
            {
                continue;
            }
            else if (tail.find(i) != tail.end() && tail[i] > 0) // merge to previous chain
            {
                --tail[i];
                ++tail[i+1];
            }
            else if (dict.find(i+1) != dict.end() && dict[i+1] > 0 &&  // can start a new chain
                     dict.find(i+2) != dict.end() && dict[i+2] > 0)
            {
                --dict[i+1];
                --dict[i+2];
                ++tail[i+3];
            }
            else
            {
                return false;
            }
            --dict[i];
        }
        
        return true;
    }
};
