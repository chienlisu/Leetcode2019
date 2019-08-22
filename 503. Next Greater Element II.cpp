class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
  
        if (size == 0)
            return {};
        else if (size == 1)
            return {-1};
        
        stack<int> myStack;
        vector<int> ans(size, -1);
        vector<bool> check(size, false);
        
        for (int i=size-1; i>=0; --i)
        {
            while (!myStack.empty() && nums[myStack.top()] <= nums[i])
            {
                myStack.pop();
            }
            if (!myStack.empty())
            {
                ans[i] = nums[myStack.top()];
                check[i] = true;
            }
            myStack.push(i);
        }
        
        for (int i=size-1; i>=0; --i)
        {
            if (check[i] == false)
            {
                while (!myStack.empty() && nums[myStack.top()] <= nums[i])
                {
                    myStack.pop();
                }
                if (!myStack.empty())
                {
                    ans[i] = nums[myStack.top()];
                    check[i] = true;
                }
                else
                    break;
            }
        }
        
        return ans;
    }
};
