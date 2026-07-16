class Solution {
public:

    int gcd(int a, int b){
        if(b==0) return a;

        int ans = gcd(b, a%b);
        return ans;

    }
    long long gcdSum(vector<int>& nums) {
        // nlogn hi hoga brute bhi kare to?
        // a>b -> gcd(a, b) == gcd(b, a%b) when b==0 a is the gcd.

        int m = nums[0];
        vector<int> gcds;

        for(int i=0; i<nums.size(); i++){
            m = max(m, nums[i]);
            gcds.push_back(gcd(m, nums[i]));
        }

        sort(gcds.begin(), gcds.end());
        // for(int i:gcds) cout << i << " ";

        int ptr1 = 0, ptr2 = gcds.size()-1;
        long long ans = 0;

        while(ptr1 < ptr2){
            ans += gcd(gcds[ptr1], gcds[ptr2]);
            ptr1++;
            ptr2--;
        }
        return ans;
    }
};