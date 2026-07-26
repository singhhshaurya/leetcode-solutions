class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans1 = 1;

        for(int i=nums.size()-3; i<nums.size(); i++) ans1 *= nums[i];

        int ans2 = nums[0]*nums[1]*(*(nums.end()-1));
        // cout << ans1 << " " << ans2;
        return max(ans1, ans2);
    }
};