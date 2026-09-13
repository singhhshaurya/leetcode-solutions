class NumArray {
public:
    // BIT TREE. ahah.
    // as we know. point update : i+(i&-i)
    // range query : i-(i&-1)
    vector<int> bit;
    int size;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        size = nums.size();
        bit.assign(size+1, 0);
        for(int i=1; i<=size; i++){
            bit[i] += nums[i-1];
            int parent = i + (i&-i);
            if(parent <= size) bit[parent] += bit[i];
        }
        // for(int i:bit) cout << i << " ";
    }

    void update(int index, int val) {
        int val2 = val - arr[index];
        arr[index] = val;
        index++;
        while(index <= size){
            bit[index] += val2;
            index += index & (-index);
        }
    }
    


    int sumRange(int left, int right){
        // 7(111) -> 6(110) -> 4(100) -> 0.
        int l1 = 0;
        int l2 = 0;
        while(left > 0){
            l1 += bit[left];
            left -= (left&-left);
        }
        right++;
        while(right > 0){
            l2 += bit[right];
            right -= (right&-right);
        }
        // cout << l1 << " " << l2 << "\n";
        return l2 - l1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */