class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> opens = {{')', '('}, {']', '['},{'}', '{'}};
        for(char c:s){
            if(opens.find(c)==opens.end()){
                stack.push_back(c);
            }else{
                if(stack.empty() || stack.back()!= opens[c]) return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};