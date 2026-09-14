class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 4ro points ko dekhna padega, one point of one rectangle must lie within the other triangle.
        // hai to mast.
        // aur koi tarika nahi hai bc
        // damn my approach WASNT correct.
        // 
        bool b1 = rec2[2] <= rec1[0] || rec2[0] >= rec1[2];
        bool b2 = rec2[3] <= rec1[1] || rec2[1] >= rec1[3];

        return !(b1 || b2);

    }
};