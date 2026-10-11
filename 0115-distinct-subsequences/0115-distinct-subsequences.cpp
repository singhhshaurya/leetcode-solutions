class Solution {
public:
    int numDistinct(string s, string t) {
        // o betche!
        // nsquare acceptable. 
        // ig backtracking se ho jana chahiye? haina?
        // nsquare hi hoga backtracking me bhi. include tabhi hoga jab what we want ke equal hai
        // nah nahi tha. 2**n.
        // okay so dp it is.
        // dp[i][j] = s[:i] tak for t[:j]
        // d

        unordered_map<char, int> ind;

        int n = s.size(), m = t.size();
        if(m>n) return 0;
        if(m==n) return s == t;

        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<min(i+1, m); j++){
                if(i!=0) dp[i][j] = dp[i-1][j];
                if(s[i] == t[j]){
                    if(j==0) dp[i][j] += 1;
                    else if(i!=0) dp[i][j] += dp[i-1][j-1];
                }
            }

        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << dp[i][j] << " "; 
        //     }
        //     cout << "\n";
        // }
        return dp[n-1][m-1];




    }
};