class Solution {
public:
    void update(int n, vector<int>& bit){
        while(n < bit.size()){
            bit[n]++;
            n += n&-n;
        }
    }
    int retrieve(int n, vector<int>& bit){
        int s = 0;
        while(n > 0){
            s += bit[n];
            n -= n&-n;
        }
        return s;
    }
    vector<int> resultArray(vector<int>& nums) {
        // okay now what.
        // matlab sorted rakhna hai bas to ordered map le sakte hai i guess to store frequency also
        // binary search on it to find elements greater. logn me ho jayega. enumerate kardo taki bad me le sake.
        // hell nah. we want logn insertions. logn queries. use segment tree. simple as that.
        int n = nums.size();
        set<int> ordered(nums.begin(), nums.end());
        vector<int> corr_index = {0};
        unordered_map<int, int> mappings;

        int curr = 1;
        for(int i:ordered) {
            corr_index.push_back(i);
            mappings[i] = curr;
            curr++;
        }
        // no we have just numbers 1 to n;
        // nums increment karna hai bas.
        // binary indexed tree se karte hai. segment tree also possible but complicated hai bc

        // things to remember:
        // 1. i&-i least significant set bit dedeta hai.
        // 2. tree[i] contains i&-i elements, ending at ith index.
        // so updating: keep doing i+= i&-i and update.
        // retrieval: minus karte raho i-= i&-i bas.

        vector<int> bit1(n+1);
        vector<int> bit2(n+1);

        update(mappings[nums[0]], bit1);
        update(mappings[nums[1]], bit2);
        vector<int> ans1 = {nums[0]};
        vector<int> ans2 = {nums[1]};

        for(int i=2; i<nums.size(); i++){
            int corr_i = mappings[nums[i]];
            int size1 = retrieve(n, bit1);
            int size2 = retrieve(n, bit2);
            // cout << nums[i] << " " << size1 << " " << size2 << "\n";

            int count1 = size1 - retrieve(corr_i, bit1);
            int count2 = size2 - retrieve(corr_i, bit2);
            // cout << nums[i] << " " << count1 << " " << count2 << "\n";
            if(count1>count2) {
                update(corr_i, bit1);
                ans1.push_back(nums[i]);
            }
            else if(count2 > count1 || size2 < size1){
                update(corr_i, bit2);
                ans2.push_back(nums[i]);
            }
            else{
                update(corr_i, bit1);
                ans1.push_back(nums[i]);
            }
        }

        for(int i:ans2){
            ans1.push_back(i);
        }
        return ans1;







    }
};