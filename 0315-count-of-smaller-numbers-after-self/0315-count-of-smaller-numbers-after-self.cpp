class Solution {
public:
    void update(vector<int>& bit, int val){
        // yaha pe 1 freq kam ho jayegi of val. 
        while(val < bit.size()){
            bit[val] --;
            val += val&(-val); // change in parent.
        }
    }
    int query(vector<int>& bit, int val){
        // left is obv 0. right is val-1, prefix sum le lena hai inka. all elements smaller than val mil jayega. ahahahahha
        val--;
        int ans = 0;
        while(val > 0){
            ans += bit[val];
            val -= val&(-val);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        // BINARY INDEXED TREE!
        // we keep FREQUENCY!! so PREFIX SUM BAN JAYEGA OHO!
        // ex [5,2,6,1] becomes [1,1,0,0,1,1] (index start from 1)
        
        int m1 = nums[0], m2=nums[0];

        for(int i:nums){
            m1 = min(m1, i);
            m2 = max(m2, i);
        }

        // i-m1 gives corresponding index in freq_arr;
        vector<int> freq_arr(m2-m1+1);
        for(int i:nums){
            freq_arr[i-m1] += 1;
        }

        // BIT IMPLEMENTATION! add in immediate parent thats it.
        vector<int> bit(freq_arr.size()+1);
        for(int i=0; i<freq_arr.size(); i++){
            int ind = i+1;
            bit[ind] += freq_arr[i];
            int parent = ind + (ind&-ind);
            if(parent < bit.size()) bit[parent] += bit[ind]; 
        }
        vector<int> ans;
        for(int i:nums){
            update(bit, i-m1+1);
            ans.push_back(query(bit, i-m1+1)); // always +1 for bit me map karne ke liye.
        }
        // i-m1 maps to freq_arr
        // +1 maps to bit.
        return ans;

    }
};