class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 2 pointers se ho jana chahiye.
        int n = nums.size();
        cout << n;
        int ptr2 = n-1;
        int sum_right = 0;
        int sum_left = 0;

        while(ptr2 >= 0 && sum_right < x){
            sum_right += nums[ptr2];
            ptr2--;
        }

        int ans = INT_MAX;
        
        int ptr1 = 0;
        if(sum_right < x) return -1;
        cout << sum_right << " " << ptr2 << "\n";
        while(ptr1 < n && ptr2 < n){
            if(sum_right+sum_left == x){
                ans = min(ans, ptr1 + (n-ptr2-1));
                sum_right -= nums[++ptr2];
            }
            while(ptr2 < n && sum_right + sum_left > x){
                sum_right -= nums[++ptr2];
            }
            while(ptr1 <= ptr2 && sum_right + sum_left < x)sum_left += nums[ptr1++];
        }
        return ans == INT_MAX ? -1 : ans;


    }
};