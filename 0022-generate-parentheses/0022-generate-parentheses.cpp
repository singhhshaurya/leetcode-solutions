class Solution {
public:
    vector<string> ans;
    int n;
    void generate_strings(int open_count, int close_count, string curr){
        if(open_count == n && close_count == n){
            ans.push_back(curr);
            return;
        }
        if(open_count != n) generate_strings(open_count+1, close_count, curr+"(");

        if(close_count != n && close_count != open_count){
            generate_strings(open_count, close_count+1, curr+")");
        }
        return;

    }
    vector<string> generateParenthesis(int n2) {
        n = n2; 
        generate_strings(0, 0, "");
        return ans;
    }
};