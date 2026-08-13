class NumArray {
public:
    vector<int> segment_tree;
    vector<int> corresponding_index; // corr. index of nums[i] as a leaf node in segment tree.
    int n;

    // forming segment tree.
    int form_tree(int left, int right, int index, vector<int>& nums){
        // cout << index << " " << left << "\n";
        if(segment_tree[index] != -1) return segment_tree[index];

        // leaf node.
        if(left == right){
            corresponding_index[left] = index;
            segment_tree[index] = nums[left];
            return nums[left]; 
        }
    
        // else query children.
        int mid = (left+right)/2;
        int ans = form_tree(left, mid, 2*index+1, nums) + form_tree(mid+1, right, 2*index+2, nums);
        segment_tree[index] = ans;
        return ans;
    }

    void update_in_tree(int addition, int segment_tree_index){
        // cout << segment_tree_index;
        segment_tree[segment_tree_index] += addition;
        if(segment_tree_index == 0) return;

        update_in_tree(addition, (segment_tree_index-1)/2);
        return;
    }

    int sumRange2(int left, int right, int curr_left, int curr_right, int index) {
        if(right < curr_left || left > curr_right) return 0;

        if(left <= curr_left && curr_right <= right) return segment_tree[index];
        
        int mid = (curr_left + curr_right)/2;
        return sumRange2(left, right, curr_left, mid, 2*index+1) + sumRange2(left, right, mid+1, curr_right, 2*index+2);
    }

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        segment_tree.assign(4*nums.size(), -1);
        corresponding_index.assign(n, 0);
        form_tree(0, nums.size()-1, 0, nums);
        // cout << "done till here\n";

    }



    void update(int index, int val) {

        int segment_tree_index = corresponding_index[index];
        int addition = val - segment_tree[segment_tree_index];
        update_in_tree(addition, segment_tree_index);
        // cout << segment_tree[0];
        // cout << "done update\n";
    }
    


    int sumRange(int left, int right){
        int s = sumRange2(left, right, 0, n-1, 0);
        // cout << "done sum range\n";
        return s;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */