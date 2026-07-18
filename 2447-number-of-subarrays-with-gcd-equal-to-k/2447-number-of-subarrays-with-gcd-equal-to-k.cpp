class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        // brute force bas
        // aathoo question
        int ans = 0;

        int GCD;
        for(int i=0; i<nums.size(); i++){
            GCD = nums[i];
            for(int j=i; j<nums.size(); j++){
                GCD = gcd(GCD, nums[j]);
                if(GCD < k) break;
                ans += GCD == k; 
            }
        }
        return ans;

    }
};