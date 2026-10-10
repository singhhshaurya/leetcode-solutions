class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // distance between nums1[i] and nums2[i] ka square.
        // square matters, square k wajah se hi ham MAXIMUM DISTANCE kam karenge obv.
        // dist = 6, dist = 4. 6->4 ya 4->2. agar square nahi hota doesnt matter jo kam kare.
        // so heap se ho jayega?

        int total_moves = k1+k2;
        int joint = 0;
        int n = nums1.size();
        vector<long long> distances;
        
        for(int i=0; i<n; i++){
            distances.push_back(abs(nums1[i]-nums2[i]));
        }
        distances.push_back(-INT_MAX);
        sort(distances.begin(), distances.end(), greater<int>());
        int ptr = 0;
        // 10, 8, 7, 4, 2 ptr at 4. 

        // for(int i:distances) cout << i << " ";
        // cout << "\n";

        while(true){
            if(total_moves >= (distances[ptr]-distances[ptr+1])*(ptr+1)){
                total_moves -= (distances[ptr]-distances[ptr+1])*(ptr+1);
                ptr++;
            }else{ // now ptr tak saare same value ke ho gaye hai subtract karke.
                int extra = total_moves / (ptr+1); // ye sabme subtract hoga (nums[0:ptr+1])
                total_moves %= (ptr+1); // ye jo bach gaya tab bhi
                distances[ptr] -= extra;
                for(int i=0; i<=ptr; i++){
                    distances[i] = distances[ptr];
                    if(i < total_moves) distances[i]--; // kam kardo bc
                }
                break;
            }
        }
        // for(int i:distances) cout << i << " ";
        // cout << "\n";

        long long ans = 0;
        for(int i=0; i<distances.size(); i++){
            if(distances[i] < 0) continue;
            ans += pow(distances[i], 2);
        }
        return ans;

    }
};