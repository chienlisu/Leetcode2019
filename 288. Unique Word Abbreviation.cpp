class ValidWordAbbr {
public:
    unordered_map<string, int> myMap;
    set<string> mySet;
    ValidWordAbbr(vector<string>& dictionary) {
        for (int i=0; i<dictionary.size(); ++i)
        {
            int len = dictionary[i].length();
            string temp;
            if (len<=2)
                temp = dictionary[i];
            else
                temp = dictionary[i].substr(0,1) + to_string(len-2) + dictionary[i].substr(len-1,1);
            
            if (myMap[temp] == 0)
                mySet.insert(dictionary[i]);
            else if(myMap[temp] == 1 && mySet.find(dictionary[i])!=mySet.end())
                continue;
            
            ++myMap[temp];
        }
    }
    
    bool isUnique(string word) {
        int len = word.length();
        string temp;
        if (len<=2)
            temp = word;
        else
            temp = word.substr(0,1)+to_string(len-2)+word.substr(len-1,1);
        
        if (myMap[temp] == 0 || (myMap[temp] == 1 && mySet.find(word)!=mySet.end()))
            return true;
        else
            return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
