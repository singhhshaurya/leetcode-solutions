class Solution {
public:
    int longestValidParentheses(string s) {
        // only ) can make it instantly invalid.
        // FUAAKK
        // look ) can make instantly invalid, we can check. but ( can also create a separation but 
        // ye pata aage jake lagega. WAIT A MINUTE
        // IF ( aya, and total_) is GREATER than total_(, OBVIOUSLY it will be matched.
        // pehle DHUNDH lo bc kon konse open ( close NAHI honge. AHA.

        vector<int> opens;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') opens.push_back(i);
            else {
                if(opens.size()) opens.pop_back();
            }
        }

        unordered_set<int> vacant_opens;
        for(int i:opens) vacant_opens.insert(i);

        int open_count = 0;
        int curr_ans = 0;
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                if(vacant_opens.find(i)==vacant_opens.end()){
                    open_count ++;
                }else{
                    ans = max(ans, curr_ans);
                    open_count = 0;
                    curr_ans = 0;
                }
            }else{
                if(open_count == 0){
                    ans = max(ans, curr_ans);
                    curr_ans = 0;
                }else{
                    open_count --;
                    curr_ans += 2;
                }
            }
        }
        return max(ans, curr_ans);

    }
};