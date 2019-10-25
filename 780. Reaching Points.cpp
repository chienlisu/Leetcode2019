class Solution {
public:
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty)
            return true;
        if (tx < sx || ty < sy)
            return false;
        
        int temp_x = tx;
        int temp_y = ty;
        
        while (temp_x > sx && temp_y > sy)
        {
            if (temp_x > temp_y)
            {
                temp_x -= temp_y;
            }
            else
            {
                temp_y -= temp_x;
            }
        }
        
        if (temp_x == sx)
        {
            return ((temp_y-sy)%temp_x == 0);
        }
        else if (temp_y == sy)
        {
            return ((temp_x-sx)%temp_y == 0);
        }
        return false;
    }
};
