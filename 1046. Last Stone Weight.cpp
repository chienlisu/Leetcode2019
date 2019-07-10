class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        if (size == 0)
            return 0;
        else if (size == 1)
            return stones[0];
        
        make_heap(stones.begin(), stones.end());
        
        int max, next;
        while (size > 1)
        {
            max = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            next = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if (max == next)
            {
                size = size-2;
            }
            else
            {
                stones.push_back(max-next);
                push_heap(stones.begin(), stones.end());
                --size;
            }
        }
        
        if (size == 0)
            return 0;
        else
            return stones.front();
    }
};
