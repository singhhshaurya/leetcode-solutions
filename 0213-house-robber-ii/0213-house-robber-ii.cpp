class Solution {
public:
    map<pair<int, int>, int> memo;

    int dp(int index, bool zeroincluded, vector<int>& nums){
        if(zeroincluded && index >= nums.size()-1) return 0;
        if (index >= nums.size()) return 0;

        if (memo.find({index, zeroincluded}) != memo.end()) {
            return memo[{index, zeroincluded}];
        }
        int include;
        int exclude;
        if(index==0){
            include = nums[index] + dp(index+2, true, nums);
            exclude = dp(index+1, false, nums);
        }
        else{
            include = nums[index] + dp(index+2, zeroincluded, nums);
            exclude = dp(index+1, zeroincluded, nums);
        }

        memo[{index, zeroincluded}] = max(include, exclude);
        return max(include, exclude);
    }

    int rob(vector<int>& nums2) {
        return dp(0, false, nums2);
        
    }
};