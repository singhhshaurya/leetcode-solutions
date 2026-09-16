class Solution {
public:
    vector<vector<vector<int>>> memo;
    int MOD = pow(10, 9) + 7;
    int dp(int index, int included, bool cont, int n, int k){
        if(included == k){
            // cout << index << " ";
            return !cont; // agar cont NA ho tabhi return kar. warna 2 bar ho jayega bc.
        }

        if(index >= n){
            return 0;
        }
        if(memo[index][included][cont]!=-1) return memo[index][included][cont];

        long long ans = 0;
        if(cont){
            ans += dp(index+1, included, true, n, k); // continue it.
            ans +=  dp(index+1, included+1, false, n, k); // break and dont draw
            ans += dp(index+1, included+1, true, n, k); // break but still draw.
        }
        else{
            ans += dp(index+1, included, true, n, k); // we draw new.
            ans += dp(index+1, included, false, n, k); // we dont draw, continue the empty.
        }
        ans %= MOD;
        memo[index][included][cont] = ans;
        return ans;
    }

    int numberOfSets(int n, int k) {
        // damn son
        // dp hi lag raha hai.
        // maybe it aint dp. prev se connection mil sa nahi raha.
        // dp[i][k] se jo maybe
        // dp[i][k] me extra wahi honge jinme i point included hai warna baki tp pehle me bhi hai hi
        // okay okay i get it then
        // is this fucking just include exclude? oh my god.
        memo.assign(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        int MOD = pow(10, 9) + 7;
        return dp(0, 0, false, n, k);
    }
};