/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findPeakIdx(MountainArray &mountainArr)
    {
        int length = mountainArr.length();
        int leftIdx = 0;
        int rightIdx = length - 1;
        int currIdx;
        
        while (leftIdx < rightIdx)
        {
            currIdx = leftIdx + (rightIdx - leftIdx)/2;
            
            int curr = mountainArr.get(currIdx);
            int next = mountainArr.get(currIdx+1);
            
            if (curr > next)
                rightIdx = currIdx;
            else
                leftIdx = currIdx+1;
        }
        return leftIdx;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int peakIdx = findPeakIdx(mountainArr);
        cout << peakIdx;
        
        if (target < min(mountainArr.get(0),mountainArr.get(length-1)) || target > mountainArr.get(peakIdx))
            return -1;
        
        int leftIdx = 0;
        int rightIdx = peakIdx; 
        int currIdx;
        
        while (leftIdx <= rightIdx)
        {
            currIdx = leftIdx + (rightIdx - leftIdx)/2;
            int curr = mountainArr.get(currIdx);
            
            if (curr == target)
                return currIdx;
            else if (curr > target)
            {
                rightIdx = currIdx-1;
            }
            else
            {
                leftIdx = currIdx+1;
            }
        }
        
        leftIdx = peakIdx+1;
        rightIdx = length-1;
        while (leftIdx <= rightIdx)
        {
            currIdx = leftIdx + (rightIdx - leftIdx)/2;
            int curr = mountainArr.get(currIdx);
            
            if (curr == target)
                return currIdx;
            else if (curr > target)
            {
                leftIdx = currIdx+1;
            }
            else
            {
                rightIdx = currIdx-1;
            }
        }
 
        return -1;
    }
};
