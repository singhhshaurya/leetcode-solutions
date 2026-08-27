class Solution {
public:
    string ans;
    bool backtrack(int ind, unordered_map<char, int>& freq, string& target){
        if(ind >= target.size()) return false;
        char letter = target[ind];
        if(freq[letter]){
            ans += letter;
            freq[letter]--;
            if(backtrack(ind+1, freq, target)) return true;
            ans.pop_back();
            freq[letter]++;
        }
        // nahi mila.
        pair<char, int> m = {'\0', 27};
        for(auto& i:freq){
            if(i.second && i.first-letter > 0 && i.first-letter < m.second){
                m = {i.first, i.first-letter};
            }
        }
        if(m.first == '\0') return false;

        ans += m.first;
        freq[m.first] --;
        vector<pair<char, int>> freq2(freq.begin(), freq.end());
        sort(freq2.begin(), freq2.end());
        for(auto& i:freq2){
            for(int j=0; j<i.second; j++) ans += i.first;
        }
        return true;

    }
    string lexGreaterPermutation(string s, string target) {
        // "abc" and "bbd"
        // okay so, ek index me bhi agar we put a letter GREATER than that one at target, bas baki sort karke laga dena hai.
        // most optimal will be saare letters EQUAL ho except last.
        // so go equal until we can, nahi hua to put greater, sort, return. 
        // backtracking se ho jana chahiye.
        unordered_map<char, int> freq;
        for(char c:s) freq[c]++;

        backtrack(0, freq, target);
        return ans;
    }
};