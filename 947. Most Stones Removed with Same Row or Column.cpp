class Solution {
public:
    vector<int> data;
    int find(int i)
    {
        if (data[i] != i)
        {
            data[i] = find(data[i]);
        }
        return data[i];
    }
    void make_union(int i, int j)
    {
        data[find(i)] = find(j);
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        // union-find init.
        // 0~9999 row, 10000~19999 col
        for (int i=0; i<20000; ++i)
        {
            data.push_back(i);
        }
        
        //union
        for (int i=0; i<stones.size(); ++i)
        {
            make_union(stones[i][0], stones[i][1]+10000);
        }
        
        // count component numbers
        set<int> components;
        for (auto i: stones)
        {
            components.insert(find(data[i[0]]));
        }
        
        // k components (with number x1,x2,...xk)
        // total = (x1-1)+(x2-1)+...+(xk-1) = (x1+...+xk) - k = n - k
        return stones.size()-components.size();
    }
};
