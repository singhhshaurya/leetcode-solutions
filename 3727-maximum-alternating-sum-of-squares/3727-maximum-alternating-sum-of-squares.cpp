class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // negatives ko positives karde pehle to.
        // sort that shi then. first half add kardo second half subtract
        // ezpz

        for(int i=0; i<nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += pow(nums[i], 2) * (i < nums.size()/2 ? -1 : 1);
        }
        return ans;
    }
};