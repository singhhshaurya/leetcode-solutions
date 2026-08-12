class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ptr1 = 0;
        unordered_map<int, int> freq;

        int ans = 0;
        for(int ptr2=0; ptr2<nums.size(); ptr2++){
            freq[nums[ptr2]]++;
            while(freq[nums[ptr2]]>k){
                freq[nums[ptr1]]--;
                ptr1 ++;
            }
            ans = max(ans, ptr2-ptr1+1);
        }
        return ans;
    }
};