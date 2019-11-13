class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> dict1;
        
        for (auto i:nums1)
            dict1.insert(i);
        
        set<int> dict2;
        vector<int> ans;
        for (auto i:nums2)
        {
            if(dict2.find(i) != dict2.end())
            {
                continue;
            }
            if(dict1.find(i) != dict1.end())
            {
                ans.push_back(i);
                dict2.insert(i);
            }
        }
        return ans;
    }
};
