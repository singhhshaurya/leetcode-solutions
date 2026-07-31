class Solution {
public:
    int minimumPushes(string word) {
        // ezpz 
        
        unordered_map<char, int> freq;
        for(char c:word) freq[c]++;

        vector<pair<int, char>> freq2;
        for(auto& i:freq) freq2.push_back({-i.second, i.first});

        sort(freq2.begin(), freq2.end());
        unordered_map<char, int> map;

        int curr = 2;
        for(auto& i:freq2) {
            map[i.second] = curr++;
            if(curr%10 == 0) curr +=2; // skip 0 and 1.
        }
        
        // for(auto& i:map) cout << i.first << " " << i.second;
        int ans = 0;
        for(char c:word){
            ans += 1 + map[c]/10;
        }
        return ans;
    }  
};