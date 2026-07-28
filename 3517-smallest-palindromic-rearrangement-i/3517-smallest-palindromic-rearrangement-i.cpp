class Solution {
public:
    string smallestPalindrome(string s) {
        // count sort. 

        string first_half = s.substr(0, s.size()/2);

        vector<int> freq(26);
        for(char c:first_half) freq[c-'a']++;

        vector<int> position = {0}; 
        for(int i:freq) position.push_back(position.back() + i);

        string sorted_first_half = first_half;
        int pos;
        for(char c:first_half){
            pos = position[c-'a']++;
            sorted_first_half[pos] = c;
        }

        string second_half = sorted_first_half;
        reverse(second_half.begin(), second_half.end());

        if(s.size()%2 == 0) return sorted_first_half + second_half;
        else return sorted_first_half + s[s.size()/2] + second_half;
        return "";
    }
};