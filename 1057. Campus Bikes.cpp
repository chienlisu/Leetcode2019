class Solution {
public:
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        int m=workers.size();
        int n=bikes.size();
        vector<pair<int, pair<int, int>>> dist;  //vector of (distance, (workerindex, bikeindex))
        
        //Get every pair of distance among workers and bikes
        //insert into dist: (distance, (workerindex, bikeindex))
        for(int i=0; i<workers.size(); i++){
            for(int j=0; j<bikes.size(); j++){
                int cdist=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                dist.push_back(make_pair(cdist, make_pair(i,j)));
            }
        }
        
        //sort by distance. If distance equal, by workerindex. If distance and workerindex equal, by bikesindex
        sort(dist.begin(), dist.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
            return a.first<b.first 
                || (a.first==b.first && a.second.first<b.second.first) 
                || (a.first==b.first && a.second.first==b.second.first && a.second.second<b.second.second);
        });
        
        //initialize two vector for assignedworker and assignedbike
        vector<int> assignedworker(m,-1);
        vector<int> assignedbike(n,-1);
        
        //traverse through each dist. If workers and bikes not assigned before assigned it. reture assignedworkers
        for(auto d:dist){
            if(assignedworker[d.second.first]==-1 && assignedbike[d.second.second]==-1) {
                assignedworker[d.second.first]=d.second.second;
                assignedbike[d.second.second]=d.second.first;
            }
        }
        
        return assignedworker;
    }
};
