class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        int size = barcodes.size();
        if (size <=2)
            return barcodes;
        
        unordered_map<int, int> myMap;
        for(int i=0; i<size; ++i)
            ++myMap[barcodes[i]];
        
        priority_queue<vector<int>> myQue; 
        vector<int> ans(size, 0);
        for (auto it = myMap.begin(); it!=myMap.end(); ++it)
        {
            myQue.push({it->second,it->first});
            //cout<<it->second<<" ";
            //cout<<it->first<<", ";
        }
        
        int j=0;
        while (!myQue.empty())
        {
            for(int i=0; i<myQue.top()[0]; ++i)
            {
                if (j>=size)
                    j = 1;
                ans[j] = myQue.top()[1];
                j = j+2;
            }
            myQue.pop();
        }
        return ans;
    }
};
