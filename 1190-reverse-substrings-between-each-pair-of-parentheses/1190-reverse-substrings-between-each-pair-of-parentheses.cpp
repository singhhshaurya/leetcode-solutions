class Solution {
public:
    string resolve(string s){
        // cout << s << "\n";
        string reversed;

        // first resolve any brackets in there.
        vector<int> stack;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') stack.push_back(i);
            if(s[i] == ')'){
                int left_ptr = stack.back();
                stack.pop_back();
                s.replace(left_ptr, i-left_ptr+1, resolve(s.substr(left_ptr+1, i-left_ptr-1)));
                // cout << s << "\n";
                i-=2;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string reverseParentheses(string s) {
        // recursively brackets kholne hai bas.
        string ans = resolve(s);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};