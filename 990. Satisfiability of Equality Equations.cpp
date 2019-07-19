class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> data(26);
        
        for (int i=0; i<equations.size(); ++i)
        {
            // prepare data for dfs
            if (equations[i][1] == '=')
            {
                int a = equations[i][0] - 'a';
                int b = equations[i][3] - 'a';
                data[a].push_back(b);
                data[b].push_back(a);
            }
        }   
        
        // dfs
        vector<int> group(26,0);
        int idx = 0;
        for (int i=0; i<data.size(); ++i)
        {
            if (group[i] == 0)
            {
                ++idx;
                group[i] = idx;
                stack<int> myStack;
                myStack.push(i);

                while (!myStack.empty())
                {
                    int curr = myStack.top();
                    myStack.pop();

                    for (int j=0; j<data[curr].size(); ++j)
                    {
                        if (group[data[curr][j]] == 0)
                        {
                            group[data[curr][j]] = idx;
                            myStack.push(data[curr][j]);
                        }
                    }
                }                    
            }
            
        }
        
        // check inequality
        for (int i=0; i<equations.size(); ++i)
        {
            if (equations[i][1] == '!')
            {
                int a = equations[i][0] - 'a';
                int b = equations[i][3] - 'a';
                if (group[a] == group[b])
                    return false;
            }
        }
        
        return true;
    }
};
