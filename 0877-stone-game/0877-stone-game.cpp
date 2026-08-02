class Solution {
public:
    vector<vector<int>> memo;
    int dp(int start, int end, bool alex, vector<int>& piles){
        if(end < start) return 0;
        if(memo[start][end] != -INT_MAX) return memo[start][end];

        int m = alex ? 1 : -1;

        int ans = m*piles[start] + dp(start+1, end, !alex, piles);
        ans = max(ans, m*piles[end] + dp(start, end-1, !alex, piles));
        memo[start][end] = ans;
        return ans;
    }
    bool stoneGame(vector<int>& piles) {
        // dp hai bas bc. bekar.
        int n = piles.size();
        memo.assign(n, vector<int>(n, -INT_MAX));
        int a = dp(0, n-1, true, piles);
        return a > 0;

    }
};