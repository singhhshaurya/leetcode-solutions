class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // aight this seems simple
        // [5,3,1,9,8] -> [3,5,1,8,9] -> [1,5,3,8,9] -> [1,3,5,8,9]
        // [5,3,1] -> [3,5,1] -> [1,5,3] swappable okay okay
        // okay so chote numbers ko zyada priority deni for switching of course.
        // is it like disjoint set, find out all the swappable  entities sort those shits
        // ig so right>
        // [5,9,3,1,8]
        int n = nums.size();
        vector<pair<int, int>> nums2;
        for(int i=0; i<n; i++){
            nums2.push_back({nums[i], i});
        }
        
        sort(nums2.begin(), nums2.end());
        vector<pair<int, int>> nums3(nums2.begin(), nums2.end());

        vector<int> ans(n, 0);

        int ptr1 = 0, ptr2;
        for(ptr2=1; ptr2<=n; ptr2++){
            if(ptr2 == n || nums2[ptr2].first - nums2[ptr2-1].first > limit){
                sort(nums3.begin()+ptr1, nums3.begin()+ptr2, cmp);
                for(int i=ptr1; i<ptr2; i++){
                    ans[nums3[i].second] = nums2[i].first;
                }
                ptr1 = ptr2;
            }
        }
        return ans;




    }
};