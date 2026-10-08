class Solution {
public:
    string removeOuterParentheses(string s) {
        // chi
        string ans;
        int count = 0;
        for(char c:s){
            if(c == '(') {
                if(count) ans.push_back(c);
                count++;
            }
            else{
                if(count!=1) ans.push_back(c);
                count--;
            }
        }
        return ans;
    }
};