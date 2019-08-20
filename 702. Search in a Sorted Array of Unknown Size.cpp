// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, h = INT_MAX;
        
        while (l <= h)
        {
            int med = l + (h-l)/2;
            int curr = reader.get(med);
            if (curr == target)
                return med;
            else if (curr > target)
                h = med-1;
            else
                l = med+1;
        }
        return -1;
    }
};
