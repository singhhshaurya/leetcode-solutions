class Solution {
public:
    int distinctSubseqII(string s) {
        // lag to dp hi raha not gonna laai.
        // 2000 hai so it can be a good 2d dp question
        // relation kya hogi hmm
        // normally to its 2**n - 1 right, every letter has choice either ye s or no
        // then repetitions hatani hai. bc maths lag raha hai yar.
        // dp[i] = normal - dp[j] for all j where s[i] = s[j] hmm.
        // define dp[i] = ith letter include karke kine banenge.
        // last e k baad wale se saare add karne hai then right
        int MOD = 1000000007;
        s.push_back('z');
        int n = s.size();
        vector<long long> dp(n, 1);
        dp[0] = 1; // dp[i] stores subsequences with last letter = dp[i].

        unordered_map<char, int> table; // stores last occurence of letters.
        // abcefge
        // {a}, {ab, b} , {abc, bc, ac, c}, {ae, abe, be, abce, bce, ace}

        
        for(int i=0; i<n; i++){
            if(i == n-1) dp[i] -= 1; // remove the 'only letter' one. last letter to border hai na. 
            for(int j=0; j<26; j++){
                if(table.find('a'+j) != table.end()){
                    dp[i] += dp[table['a'+j]];
                    dp[i] %= MOD;
                }
            }
            table[s[i]] = i;
        }
        return dp.back();

        
    }
};