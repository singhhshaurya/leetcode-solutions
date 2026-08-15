class Solution {
public:
    int jump(vector<int>& nums) {
        // okay minimum no of jumps.
        // dp kare to 1d dp hoga but har recursion me we can go max 1000. it will be 10**7. will it work?
        // so basically if jump = 4 (starting) nums[:4] tak max dundho. that will be our new jump.
        // works? max in the sense nums[i] + i (max distance ofc)

        int jumps = nums[0];
        int m = 0;
        int ans = 1;

        for(int i=1; i<nums.size(); i++){
            if(i > jumps){
                // cout << i << " " << m << "\n";
                jumps = m;
                m = 0;
                ans += 1;
            }
            m = max(m, nums[i]+i);
        }
        if(nums.size()==1) return 0;
        return ans;
    }
};