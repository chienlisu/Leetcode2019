class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int size_ho = houses.size();
        int size_he = heaters.size();
        
        if (size_ho == 0)
            return 0;
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        //cout << houses[0] <<endl;
        //cout << heaters[0] <<endl;
        //cout << houses[size_ho-1]<<endl;
        //cout << heaters[size_he-1]<<endl;
        
        int i=0, j=0;
        int ans = max(0, heaters[0]-houses[0]);
        while ((j < size_ho) && (houses[j] <= heaters[0]))
        {
            ++j;
        }
        
        while ((i < size_he - 1) && (j < size_ho))
        {
            int med = heaters[i] + (heaters[i+1]-heaters[i])/2;
            while (j < size_ho && houses[j] >= heaters[i] && houses[j] <= heaters[i+1])
            {
                if (houses[j] <= med)
                    ans = max(ans, houses[j]-heaters[i]);
                else
                    ans = max(ans, heaters[i+1]-houses[j]);
                
                ++j;
            }
            ++i;
        }
        if (j < size_ho)
        {
            ans = max(ans, houses[size_ho-1]-heaters[size_he-1]);
        }
        return ans;
    }
};
