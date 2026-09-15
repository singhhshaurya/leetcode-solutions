class Solution {
public:
    vector<int> memo;
    int dp(int ind, vector<vector<int>>& palindromes){
        if(ind >= palindromes.size()) return 0;
        if(memo[ind]!=-1) return memo[ind];

        int ans = 0;
        for(int ptr2:palindromes[ind]){
            ans = max(ans, 1+dp(ptr2+1, palindromes));
        }
        ans = max(ans, dp(ind+1, palindromes)); // exclude all of em.
        memo[ind] = ans;
        return ans;
    }
    int maxPalindromes(string s, int k) {
        // nsquare possible. dp hi hoga bc.
        // i mean find all palindromes, after that its include exclude right
        // itna easy ho sakta?
        int n = s.size();
        memo.assign(n, -1);
        int ptr1, ptr2;
        vector<vector<int>> palindromes(n);
        for(int i=0; i<n; i++){ // center hai ye.
            ptr1 = i, ptr2 = i;
            while(ptr1 >= 0 && ptr2 < n){
                if(s[ptr1] == s[ptr2]){
                    if(ptr2-ptr1+1 >=k) palindromes[ptr1].push_back(ptr2);
                }else break;
                ptr1 --;
                ptr2 ++;
            }
            ptr1 = i, ptr2 = i+1; // even length.
            while(ptr1 >= 0 && ptr2 < n){
                if(s[ptr1] == s[ptr2]){
                    if(ptr2-ptr1+1 >=k) palindromes[ptr1].push_back(ptr2);
                }else break;
                ptr1 --;
                ptr2 ++;
            }
        }
        int ans = dp(0, palindromes);
        return ans;
    }
};