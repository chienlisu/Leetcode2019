class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        int size = wordList.size();
        map<string, vector<string>> wordDict;
        
        for (int i=0; i<size; ++i)
        {
            for (int j=0; j<wordList[i].length(); ++j)
            {
                string index = wordList[i].substr(0, j) + "*" + wordList[i].substr(j+1, wordList[i].length()-j-1);
                wordDict[index].push_back(wordList[i]);
            }
        }
        
        set<string> visited;
        queue<pair<string, int>> myQue;
        
        int num = 1;
        myQue.push(pair<string, int>(beginWord, num));
        visited.insert(beginWord);
        
        while (!myQue.empty())
        {
            pair<string, int> curr = myQue.front();
            myQue.pop();
            
            for (int i=0; i<curr.first.length(); ++i)
            {
                string index = curr.first.substr(0, i) + "*" + curr.first.substr(i+1, curr.first.length()-i-1);
                for (int j=0; j<wordDict[index].size(); ++j)
                {
                    string str = wordDict[index][j];
                    if (visited.find(str) != visited.end())
                        continue;
                    else
                        visited.insert(str);
                    
                    if (str == endWord)
                        return curr.second + 1;
                    
                    myQue.push(pair<string, int>(str, curr.second+1));
                }
            }
        }
        return 0;
    }
};
