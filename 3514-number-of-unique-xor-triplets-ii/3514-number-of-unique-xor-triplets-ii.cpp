class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // nsquare me to easy hai
        // karde?

        int m = *max_element(nums.begin(), nums.end());
        int p = 1;
        while(p<=m) p <<= 1;
        vector<int> arr(p);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                arr[nums[i]^nums[j]] = 1;
            }
        }

        vector<int> arr2;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]) arr2.push_back(i);
        }

        arr.assign(p, 0);
        for(int i=0; i<nums.size(); i++){
            for(int j:arr2){
                arr[nums[i]^j] = 1;
            }
        }
        return count(arr.begin(), arr.end(), 1);
    }
};