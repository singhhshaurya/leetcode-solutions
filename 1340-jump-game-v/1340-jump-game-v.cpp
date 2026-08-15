class Solution {
public:
    vector<int> memo;
    int dp(int ind, vector<int>& arr, int d){
        if(memo[ind]!=-1) return memo[ind];

        int ans = 1;
        for(int i=1; i<=d; i++){
            if(ind+i >= arr.size()) break;
            if(arr[ind+i]>=arr[ind]) break;

            ans = max(ans, 1+dp(ind+i, arr, d));
        }

        for(int i=1; i<=d; i++){
            if(ind-i<0) break;
            if(arr[ind-i] >= arr[ind]) break;
            ans = max(ans, 1+dp(ind-i, arr, d));
        }
        memo[ind] = ans;
        return ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        // so jump ki ek range hai and
        // jump can only happen in beech me koi obstacle na ho bc.
        // dp hai to. return nahi aa sakte obv to circular bhi nahi hoga.
        memo.assign(arr.size(), -1);

        int ans = 1;
        for(int i=0; i<arr.size(); i++){
            ans = max(ans, dp(i, arr, d));
        }
        return ans;


    }
};