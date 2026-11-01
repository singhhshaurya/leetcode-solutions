class Solution {
public:
    int minMoves(vector<int>& nums) {
        // n-1 elements saare karne hai. damn.
        // same as reducing one element -1 right? shifted hai bas
        // yea same hai. smallest se difference lelo bas
        int m = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i:nums) ans += i-m;
        return ans; 
    }
};