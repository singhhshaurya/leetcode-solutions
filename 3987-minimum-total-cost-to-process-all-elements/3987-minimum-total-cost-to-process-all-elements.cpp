class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        // normal count karlete hai then sum of first n integers lelenge bc.
        int MOD = 1000000007;
        int ans = 0;
        long long k2 = k;

        int temp;
        for(int i:nums){
            if(k2 >= i) k2 -= i;
            else{
                temp = (i-k2-1)/k + 1;
                ans += temp;
                ans %= MOD;
                k2 += k*temp - i;
            }
        }
        return ((1ll*ans*(ans+1))/2)%MOD;

    }
};