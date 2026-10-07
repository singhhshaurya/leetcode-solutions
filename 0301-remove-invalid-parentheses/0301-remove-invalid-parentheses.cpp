class Solution {
public:
    vector<vector<int>> answer;
    int count_closed;
    int checker(string& s, vector<int>& removed, int index){
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(removed[i]) continue;
            if(s[i] == '(') {
                count ++;
                if(count > count_closed && i < index) return 0;
            }
            if(s[i] == ')'){
                if(count == 0){
                    if(i < index) return -1; // prune that shi
                    else return 0; // baad me fix kar sakte ho
                }
                else count --;
            }
        }
        return count == 0;
    }
    void recurse(int index, string& s, vector<int>& removed){
        int check = checker(s, removed, index);
        // cout << index << " " << check << "\n";
        if(check == -1) return;
        if(check == 1){
            answer.push_back(removed);
            return;
        }
        if(index >= s.size()) return;

        // include this shit.
        recurse(index+1, s, removed);
        // if bracket hai HATAO
        if(s[index] == '(' || s[index] == ')'){
            removed[index] = 1;
            recurse(index+1, s, removed);
            removed[index] = 0;
        }
        return;
    }
    static bool cmp(vector<int>& a, vector<int>& b){
        return count(a.begin(), a.end(), 1) < count(b.begin(), b.end(), 1);

    }
    vector<string> removeInvalidParentheses(string s) {
        // seedha brute karne me kya dikkat hai.
        // either remove or not.
        // mark no of removes.
        // last me minimum lelo bas.
        // 2**25 jayega. each constant time?
        // 3*10**7 jayega. seems good. actually jaldi hi ho jayega pura end tak nahi hi jayega
        int n = s.size();

        count_closed = 0;
        for(char c:s) count_closed += c == ')';

        vector<int> removed(n);
        recurse(0, s, removed);

        sort(answer.begin(), answer.end(), cmp);
        int min_l = count(answer[0].begin(), answer[0].end(), 1);
        set<string> ans2;
        for(auto& i:answer){
            string ans;
            if(count(i.begin(), i.end(), 1) > min_l) break;
            for(int j=0; j<s.size(); j++){
                if(!i[j]) ans+=s[j];
            }
            ans2.insert(ans);
        }
        return vector<string>(ans2.begin(), ans2.end());
    }
};