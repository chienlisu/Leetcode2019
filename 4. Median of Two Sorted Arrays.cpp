class Solution {
public:
    // drop k/2 numbers each time, to make it O(log K)
    int findKth(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) // k is order, not index
    {
        if (i >= nums1.size())
        {
            return nums2[j + k - 1];
        }
        else if (j >= nums2.size())
        {
            return nums1[i + k - 1];
        }
        
        if (k == 1)
        {
            return min(nums1[i], nums2[j]);
        }
        
        int num1 = INT_MAX, num2 = INT_MAX;
        int idx1 = i + (k/2) - 1;
        int idx2 = j + (k/2) - 1;
        
        if (idx1 < nums1.size())
        {
            num1 = nums1[idx1];
        }
        if (idx2 < nums2.size())
        {
            num2 = nums2[idx2];
        }
        
        if (num1 < num2)
        {
            return findKth(nums1, nums2, idx1+1, j, k-(k/2));
        }
        else
        {
            return findKth(nums1, nums2, i, idx2+1, k-(k/2));
        }        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        
        if (total %2 == 1)
        {
            return findKth(nums1, nums2, 0, 0, (total/2)+1);
        }
        else
        {
            return (findKth(nums1,nums2,0,0, (total/2)) + findKth(nums1,nums2,0,0, (total/2)+1))/2.0 ;
        }
    }
};
