class Solution {
public:
    string smallestPalindrome(string s) {
        string first_half = s.substr(0, s.size()/2);
        sort(first_half.begin(), first_half.end());
        
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        if(s.size()%2 == 0) return first_half + second_half;
        else return first_half + s[s.size()/2] + second_half;
        return "";
    }
};