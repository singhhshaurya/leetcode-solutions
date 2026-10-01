class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int m = 0;
        for(int i:nums) m = max(m, abs(i*1ll));

        int ans = 0;
        int bit_length = bit_width((unsigned int)m);
        for(int i=0; i<bit_length; i++){
            int count = 0;
            for(long long int num:nums){
                num = abs(num);
                if(num & 1<<i) count ++;
            }
            // cout << i << " " << count << " ";
            if(count%3 == 1) ans += 1<<i; // iss bit ko 1 kardo in final answer
        }
        cout << ans;

        // checking for negative.
        int count = 0;
        for(int i:nums) count += i==ans;
        return count==1 ? ans : -ans;



    }
};