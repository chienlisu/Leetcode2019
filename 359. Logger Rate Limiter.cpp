class Logger {
public:
    unordered_map<string, int> dict;
    /** Initialize your data structure here. */
    Logger() {
    
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (dict.find(message) == dict.end())
        {
            dict[message] = timestamp;
            return true;
        }
        else
        {   
            if (timestamp - dict[message] >= 10)
            {
                dict[message] = timestamp;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
