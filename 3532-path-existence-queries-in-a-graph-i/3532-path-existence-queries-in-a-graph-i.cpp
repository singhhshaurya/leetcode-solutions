class Solution {
public:
    int binary_search(vector<int>& gaps, int ind){
        int low = 0, high = gaps.size()-1, mid;
        while(low <= high){
            mid = (low+high)/2;
            if(gaps[mid]>=ind) high = mid-1;
            else low = mid + 1;
        }
        if(high == -1) return gaps[low];
        if (abs(ind - gaps[low]) < abs(ind-gaps[high])) return gaps[low];
        return gaps[high];
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // seems ezpz.
        // i to j ke beech gap > maxDiff nahi aana chahiye bas right
        // to disjoint sets bana sakte ig? bas parent check karna hai right
        // or we can just binary search on gaps to see the closest gap, if andar hai matlab false.
        // first lets do binary search

        vector<int> gaps;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] > maxDiff) gaps.push_back(i);
        }
        gaps.push_back(n);
        // for(int i:gaps) cout << i << " ";
        // cout << "\n";

        vector<bool> ans;
        int u, v, mid, gap_ind;


        for(auto& i:queries){
            u = i[0], v=i[1];
            if(v<u){
                int temp = u; 
                u = v; 
                v = temp;
            }
            mid = (u+v)/2;
            gap_ind = binary_search(gaps, mid);
            // cout << u << " " << v << " " << gap_ind << "\n";

            if(gap_ind < u || gap_ind >= v || u == v) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

        
    }
};