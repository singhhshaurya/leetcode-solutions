class Solution {
public:
    int resolve(string s){
        if(s == "") return 1;

        int ans = 0;
        vector<int> stack;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') stack.push_back(i);
            else{
                int left_ptr = stack.back();
                stack.pop_back();
                if(stack.empty()) {
                    if(i == left_ptr+1) ans += 1; // () hai matlab
                    else ans += resolve(s.substr(left_ptr+1, i-left_ptr-1))*2; //andar ka nikal, *2.
                }
            }
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        return resolve(s);
    }
};