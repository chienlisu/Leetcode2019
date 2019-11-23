class Solution {
public:
    bool canConvert(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        if (len1 != len2)
            return false;
        if (len1 <= 1 || str1 == str2)
            return true;
        
        // if str2 already use all characters => impossible to transfer (no temporary character to use)
        set<int> dict;
        for (auto i:str2)
        {
            dict.insert(i-'a');
        }
        if (dict.size() == 26)
            return false;
        
        
        // check if same character in str1 maps to different characters to str2 => impossible to transfer
        unordered_map<char,char> mapping;
        for (int i=0; i<str1.length(); ++i)
        {
            if(mapping.find(str1[i]) != mapping.end() && mapping[str1[i]] != str2[i])
            {
                return false;
            }
            mapping[str1[i]] = str2[i];
        }
        return true;
    }
};
