class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // top down karte hai khatam
        // dp[i][j][xor] = dp[i-1][j][curr^xor] | dp[i][j-1][curr^xor] simple.

        int m = grid.size(), n = grid[0].size();
        int maxim = 0;
        for(auto& i:grid){
            for(int j:i) maxim = max(j, maxim);
        }

        int maxim2 = 1;
        while(maxim2 <= maxim) maxim2 <<= 1;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxim2+1)));

        dp[0][0][grid[0][0]] = 1;
        //cout << maxim2;
        int curr;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                curr = grid[i][j];
                for(int xor_val=0; xor_val<maxim2; xor_val++){
                    // cout << curr << " " << xor_val << " " << (curr^xor_val) << " ";
                    if(i!=0) dp[i][j][xor_val] |= dp[i-1][j][curr^xor_val];
                    if(j!=0) dp[i][j][xor_val] |= dp[i][j-1][curr^xor_val]; 
                    // cout << dp[i][j][xor_val] << "\n"; 
                }
            }
        }
        for(int i=0; i<=maxim2; i++){
            if(dp[m-1][n-1][i]) return i;
        }
        return 0;
    }
};