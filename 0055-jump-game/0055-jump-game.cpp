class Solution {
public:
    bool canJump(vector<int>& nums) {
        // so you dont have to land on a zero thats it.
        // go to all zeroes, then waha se left ja jab tak koi jump aisa na mile jo uss zero ko paar karne layak ho. thats it?

        int n = nums.size();
        int m = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0 && i!=n-1){
                if(m <= i) return false;
            }
            m = max(m, nums[i]+i);
        }
        return true;
    }
};