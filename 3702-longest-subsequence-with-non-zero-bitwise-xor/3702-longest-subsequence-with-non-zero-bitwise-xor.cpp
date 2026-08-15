class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // i mean its either length-1 or length right?
        // 4 xor 4 = 0 xor anything = anything
        // wait 0 bhi ho sakte hai bc.

        int x = 0;
        int non_zero = 0;
        for(int i:nums) {
            x ^= i;
            non_zero += i!=0;
        }

        if(x==0){
            if(non_zero) return nums.size()-1;
            return 0;
        }
        return nums.size();

    }
};