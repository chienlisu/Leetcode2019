/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    bool checkMatch(string s1, string s2, int n)
    {
        int count = 0;
        for (int i=0; i<s1.length(); ++i)
        {
            if (s1[i] == s2[i])
                ++count;
        }
        return (count == n);
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        
        for (int i=0; i<10; ++i)
        {
            string target = wordlist[rand()%wordlist.size()]; //random select
            int curr = master.guess(target);
            if (curr == 6)
                return;
            
            vector<string> temp={};
            for (auto x:wordlist)
            {
                if (checkMatch(target, x, curr))
                    temp.push_back(x);
            }
            wordlist = temp;
            cout<< temp.size() << endl;
        }
        return;
    }
};
