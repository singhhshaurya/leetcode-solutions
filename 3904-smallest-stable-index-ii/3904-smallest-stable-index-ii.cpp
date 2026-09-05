class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // kya bakwas question hai bc.
        int n = nums.size();
        vector<int> minimums(n);

        int m1 = nums.back();
        for(int i=n-1; i>=0; i--){
            m1 = min(m1, nums[i]);
            minimums[i] = m1;
        }

        m1 = nums[0];
        for(int i=0; i<n; i++){
            m1 = max(nums[i], m1);
            if(m1-minimums[i] <= k) return i;
        }
        return -1;



    }
};