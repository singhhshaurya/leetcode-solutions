class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> k;
        for(auto& i:knowledge){
            k[i[0]] = i[1];
        } 
        int ptr = 0, left_ptr;
        string subs, replace, ans;

        vector<int> stack;
        while(ptr < s.size()){
            if(s[ptr] == '(') stack.push_back(ptr);
            if(s[ptr] == ')'){
                left_ptr = stack.back();
                stack.pop_back();
                subs = s.substr(left_ptr+1, ptr - left_ptr -1);
                if(k.find(subs) == k.end()) replace = "?";
                else replace = k[subs];
                ans += replace;
                // cout << left_ptr << " " << ptr << " " << subs << "LALA" << replace << "\n";
            }
            if(s[ptr] != ')' && stack.empty()) ans.push_back(s[ptr]);
            ptr++;
        }
        return ans;
    }
};