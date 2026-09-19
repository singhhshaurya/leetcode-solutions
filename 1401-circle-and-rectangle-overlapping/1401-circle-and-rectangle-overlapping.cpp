class Solution {
public:
    bool checker_rectangle(int x, int y, int x1, int y1, int x2, int y2){
        return !(x < x1 || x > x2 || y < y1 || y > y2);
    }
    bool checker_circle(int x, int y, int xCenter, int yCenter, int radius){
        return pow(x-xCenter, 2) + pow(y-yCenter, 2) <= pow(radius, 2);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // aathoo question lag raha hai.
        // so radius is just 2000, do we go for brute force?
        // go for every point in circle, see if it lies in the rectangle or not.
        // nsquare hoga, realtively dekhe to kam nsquare se
        // yea ig so
        
        for(int x=xCenter-radius; x<=xCenter+radius; x++){
            for(int y = yCenter-radius; y<=yCenter+radius; y++){
                bool b1 = checker_circle(x, y, xCenter, yCenter, radius);
                bool b2 = checker_rectangle(x, y, x1, y1, x2, y2);
                if(b1 && b2) return true;
            }
        }
        return false;



    }
};