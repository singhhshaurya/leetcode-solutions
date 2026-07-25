class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // mmmm
        // to get x, i xor i xor x kardo bas, i is anything.
        // bas 0 laane ke liye n >= 3 hona chahiye thats it.
        // HELL NAH. 
        int n = nums.size();
        if(n<3) return n;
        
        int p = 1;
        while(p<=n) p <<= 1;
        
        return p;

    }
};