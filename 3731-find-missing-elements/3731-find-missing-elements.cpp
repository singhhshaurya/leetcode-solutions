class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int m1 = *min_element(nums.begin(), nums.end());
        int m2 = *max_element(nums.begin(), nums.end());

        vector<int> freq(m2-m1+1, 0);
        for(int i:nums) freq[i-m1] = 1;
        
        vector<int> ans;
        for(int i=0; i<freq.size(); i++){
            if(!freq[i]) ans.push_back(i+m1);
        }
        return ans;
    }
};