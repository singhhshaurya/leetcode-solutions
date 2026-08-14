class Solution {
public:
    int maximumLengthSubstring(string s) {
        // bhap
        int ptr1 = 0;
        unordered_map<int, int> freq;
        int ans = 0;

        for(int ptr2=0; ptr2<s.size(); ptr2++){
            // cout << ptr1 << " " << ptr2 << "\n";
            freq[s[ptr2]] ++;
            while(freq[s[ptr2]] > 2)freq[s[ptr1++]]--;
            ans = max(ans, ptr2-ptr1+1);
        }
        return ans;
    }

};