class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mapping;
        mapping['0'] = '0';
        mapping['1'] = '1';
        mapping['6'] = '9';
        mapping['8'] = '8';
        mapping['9'] = '6';
        
        int len = num.length();
        
        for (int i=0; i<len/2; ++i)
        {
            if (mapping.find(num[i]) == mapping.end() ||
                mapping[num[i]] != num[len-1-i])
            {
                return false;
            }
        }
        if (len%2 !=0 && 
            (mapping.find(num[len/2]) == mapping.end() ||
             mapping[num[len/2]] == '9' || mapping[num[len/2]] == '6'))
            return false;
        return true;
    }
};
