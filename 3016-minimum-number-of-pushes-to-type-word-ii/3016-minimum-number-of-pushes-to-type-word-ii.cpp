class Solution {
public:
    int minimumPushes(string word) {
        // ezpz 
        vector<int> freq(26);
        for(char c:word) freq[c-'a']++;

        vector<pair<int, char>> freq2;
        for(int i=0; i<26; i++){
            freq2.push_back({-freq[i], 'a'+i});
        }

        sort(freq2.begin(), freq2.end());
        vector<int> map(26);
        
        int curr = 2;
        for(auto& i:freq2) {
            map[i.second - 'a'] = curr++;
            if(curr%10 == 0) curr +=2; // skip 0 and 1.
        }

        // for(auto& i:map) cout << i.first << " " << i.second;
        int ans = 0;
        for(char c:word){
            ans += 1 + map[c-'a']/10;
        }
        return ans;
    }  
};