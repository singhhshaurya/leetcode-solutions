class Solution {
public:
    vector<int> memo;
    vector<int> visited;

    bool dp(int ind, vector<int>& arr){
        if(ind < 0 || ind >= arr.size()) return false;

        if(visited[ind]) return false; // no circular.
        visited[ind] = 1;

        if(arr[ind] == 0) return true;
        if(memo[ind] != -1) return memo[ind];

        bool ans = dp(ind+arr[ind], arr) | dp(ind-arr[ind], arr);
        memo[ind] = ans;
        return ans;

    }
    bool canReach(vector<int>& arr, int start) {
        // o le 0 pahuchna hai ab
        // dp lagana hai matlab bas. bekar.
        memo.assign(arr.size(), -1);
        visited.assign(arr.size(), 0);
        return dp(start, arr);
    }
};