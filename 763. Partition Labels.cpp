class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int>> table(26);
        
        for (int i=0; i<S.length(); ++i)
            table[S[i]-'a'].push_back(i);
        int idx = 0;
        while (idx < table.size())
        {
            if (table[idx].empty())
                table.erase(table.begin()+idx);
            else
                ++idx;
        }

        sort(table.begin(), table.end(), [](vector<int>&a, vector<int>b){return(a[0]<b[0]);});
        
        for (int i=0; i<table.size();++i)
        {    for (int j=0; j<table[i].size(); ++j)
                cout <<table[i][j]<<",";
            cout<<endl;
        }       
      
        int start = -1;
        int end = -1;
        idx = 0;
        vector<int> ans;
        while(idx < table.size())
        {
            //cout <<idx<<endl;
            start = table[idx][0];
            end = table[idx][table[idx].size()-1];
            while (idx < table.size() && table[idx][0] <= end)
            {
                end = max(end, table[idx][table[idx].size()-1]);
                ++idx;
            }
            ans.push_back(end-start+1);
        }
        return ans;
    }
};
