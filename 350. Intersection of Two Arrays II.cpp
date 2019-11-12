class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        vector<int> ans;
        
        for (auto i:nums1)
        {
            if (map1.find(i) == map1.end())
                map1[i] = 1;
            else
                ++map1[i];
        }
        
        for (auto i:nums2)
        {
            if (map1.find(i) != map1.end() && map1[i] > 0)
            {
                --map1[i];
                ans.push_back(i);
            }
        }
        return ans;    
    }
};
