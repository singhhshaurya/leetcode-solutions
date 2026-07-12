class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // nlogn se better ho sakta hai?

        vector<pair<int, int>> arr2;
        for(int i=0; i<arr.size(); i++){
            arr2.push_back({arr[i], i});
        }
        sort(arr2.begin(), arr2.end());

        int rank = 1;
        vector<int> ans(arr.size(), 0);

        for(int i=0; i<arr2.size(); i++){
            ans[arr2[i].second] = rank;
            if(i != arr2.size()-1 && arr2[i+1].first>arr2[i].first) rank ++;
        }
        return ans;
    }
};