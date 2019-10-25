class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
    int minSize;
    int maxSize;
        
    MedianFinder() {
        minSize = 0;
        maxSize = 0;
    }
    
    void addNum(int num) {
        
        int minTop = minSize > 0? minHeap.top():INT_MIN;
        int maxTop = maxSize > 0? maxHeap.top(): INT_MAX;
        
        if (num >= minTop)
        {
            minHeap.push(num);
            ++minSize;
            if (minSize > maxSize + 1)
            {
                int temp = minHeap.top();
                minHeap.pop();
                --minSize;
                maxHeap.push(temp);
                ++maxSize;
            }
        }
        else if (num <= maxTop)
        {
            maxHeap.push(num);
            ++maxSize;
            if (maxSize > minSize + 1)
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                --maxSize;
                minHeap.push(temp);
                ++minSize;
            }
        }
        else
        {
            if (minSize > maxSize)
            {
                maxHeap.push(num);
                ++maxSize;
            }
            else
            {
                minHeap.push(num);
                ++minSize;
            }
        }
    }
    
    double findMedian() {
        if (minSize > maxSize)
        {
            return minHeap.top();
        }
        else if (minSize < maxSize)
        {
            return maxHeap.top();
        }
        else
        {
            return (minHeap.top() + maxHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
