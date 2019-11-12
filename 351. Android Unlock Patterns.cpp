class Solution {
public:
    bool isValid(int curr, int last, vector<bool>& visited)
    {
        // repeated digits
        if (visited[curr])
            return false;
        
        // adjacents or knight moves
        if ((curr+last)%2 == 1)
            return true;
        
        // 0->4->8 or 2->4->6 or 3->4->5 or 1->4->7
        int med = (curr + last)/2;
        if (med == 4)
            return visited[med]; // if center is visited, then this is valid.
        
        // diagonal adjacents (not in the same low or same column)
        if ((curr%3) != (last%3) && (curr/3) != (last/3))
            return true;
        
        return visited[med]; // other cases: 4 edges (0->1->2, 6->7->8, 0->3->6, 2->5->8), depends on center.
    }
    void backTracking(int& sum, int idx, int len, int& m, int& n, vector<bool>& visited)
    {
        if (len >=m && len <=n )
        {
            ++sum;
        }
        if (len == n)
        {
            return;
        }
        
        for (int i=0; i<9; ++i)
        {
            if (isValid(i, idx, visited))
            {
                visited[i] = true;
                backTracking(sum, i, len+1, m, n, visited);
                visited[i] = false;
            }
        }
    }
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(9, false); //0~8 -> 1~9
        int sum = 0;
        
        vector<int> test = {0,1,4};
        for (auto i:test)
        //for (int i=0; i<9; ++i)
        {
            if (i == 4)
                sum += (3*sum); // 0,2,6,8 are the same; 1,3,5,7 are the same
            
            visited[i] = true;
            backTracking(sum, i, 1, m, n, visited);
            visited[i] = false;
        }
        return sum;
    }
};
