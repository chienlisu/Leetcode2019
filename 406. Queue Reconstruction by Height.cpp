class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        vector<vector<int>> ans;  
    
        sort(people.begin(), people.end(), 
             [](vector<int> A, vector<int> B){return (A[0]>B[0] || (A[0]==B[0] && A[1] < B[1]) );});
        
        
        for (int i=0; i<size; ++i)
        {
            if (people[i][1] == ans.size())
                ans.push_back(people[i]);
            else
                ans.insert(ans.begin()+people[i][1], people[i]);
        }
        return ans;
    }
};
