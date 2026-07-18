class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int m1 = nums[0], m2 = nums[0];

        for(int i:nums){
            m1 = min(m1, i);
            m2 = max(m2, i);
        }

        return gcd(m2, m1);
    }
};