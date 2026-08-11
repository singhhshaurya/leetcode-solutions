class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        int ptr = 1;
        while(ptr < nums.size() && nums[ptr] == nums[ptr-1]+1) s += nums[ptr++];

        unordered_set<int> nums_set(nums.begin(), nums.end());
        while(nums_set.find(s)!=nums_set.end()) s++;
        return s;


    }
};