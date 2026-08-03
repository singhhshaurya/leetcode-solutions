class Solution {
public:
    vector<vector<int>> memo;
    int dp(int index, bool alex, vector<int>& stoneValue){
        if(index >= stoneValue.size()) return 0;

        if(memo[alex][index] != -INT_MAX) return memo[alex][index];

        int ans = stoneValue[index] - dp(index+1, !alex, stoneValue);
        if(index < (int)stoneValue.size()-1) ans = max(ans, stoneValue[index]+stoneValue[index+1]-dp(index+2, !alex, stoneValue));
        if(index < (int)stoneValue.size()-2) ans = max(ans, stoneValue[index]+stoneValue[index+1]+stoneValue[index+2]-dp(index+3, !alex, stoneValue));

        memo[alex][index] = ans;
        return ans;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        // easy lag raha ye to.
        // dp hi to hai bas?
        int n = stoneValue.size();
        memo.assign(2, vector<int>(n, -INT_MAX));
        long long a = dp(0, 1, stoneValue);
        // for(auto& i:memo){
        //     for(int j:i) cout << j << " ";
        //     cout << "\n";
        // }

        if(a>0) return "Alice";
        if(a<0) return "Bob";
        return "Tie";

    }
};