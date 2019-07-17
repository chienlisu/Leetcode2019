class Solution {
public:
    void myDFS(vector<vector<int>>& rooms, vector<int>& visited, int i)
    {
        if (visited[i] == 1)
            return;
        
        visited[i] = 1;
        
        for (int j=0; j<rooms[i].size(); ++j)
        {
            myDFS(rooms, visited, rooms[i][j]);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<int> visited(size, 0);
        
        //for (int i=0; i<size; ++i)
        {
            myDFS(rooms, visited, 0);
        }
        
        for (int i=0; i<size; ++i)
        {
            if (visited[i] == 0)
                return false;
        }
        return true;
    }
};
