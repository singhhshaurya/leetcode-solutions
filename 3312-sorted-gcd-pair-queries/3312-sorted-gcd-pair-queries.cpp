class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // n*(n-1)/2 total ja sakta. nsquare
        // bc kaise hoga ye.
        // sort na karna hota to easy hota bc
        // sort karne k baad randomised order hoga. wo predict karna hoga ab hame.
        // somehow count karna hoga how many pairs have gcd 'g'.
        // uske bad to prefix sum hoga, usme binary search
        // so how do we COUNT
        // sieve lagega. remember that nlogn lagta usme.
        // 2 me bhale n/2 lage, as we increase i, kam hote rehta thats why nlogn
        // inclusion exclusion principle check out dsa algo 2
        // 2 se divisible total 5 elements hai. total 10 pairs ban sakte inke.
        // 4 ke divisible total 2 elements hai. inke total 1 hi pair ban sakta
        // 6 se divisible total 1. no pair.
        // so pairs with gcd = 2 = (10-1-0). sounds correct?

        int m = *max_element(nums.begin(), nums.end());
        vector<int> freq(m+1, 0);
        for(int i:nums) freq[i] ++;

        vector<int> divisors(m+1, 0); // no of elements divisible by ith index.
        divisors[1] = nums.size();

        int count;
        for(int i=2; i<=m; i++){
            count = 0;
            for(int j=i; j<=m; j+=i){
                count += freq[j];
            }
            divisors[i] = count;
        }
        // for(int i:divisors) cout << i << " ";
        // cout << "\n";

        vector<long long> count_gcd(m+1, 0);

        // count_gcd[2] = divisors[2] - (divisors[4] + divisors[6]...)
        // count_gcd[3] = divisors[3] - (divisors[6] + divisors[9]+divisors[12]...) 

        long long curr;
        for(int i=m; i>0; i--){
            curr = (1ll*divisors[i]*(divisors[i]-1))/2;

            for(int j=i*2; j<=m; j+=i){
                curr -= count_gcd[j];
            }
            count_gcd[i] = curr;

        }
        // for(int i:count_gcd) cout << i << " ";

        // prefix sum
        vector<long long> prefix_sum_gcd = {0};

        for(long long i:count_gcd) prefix_sum_gcd.push_back(prefix_sum_gcd.back() + i);
        // cout << nums.size() << " " << m << " " << prefix_sum_gcd.back() << "\n"; 


        // binary search
        vector<int> ans;
        long long low, high, mid;
        for(long long i:queries){
            low = 0, high = m+1;

            while(low<=high){
                mid = (low+high)/2;
                if(prefix_sum_gcd[mid]>i) high = mid-1;
                else low = mid+1;

            }
            ans.push_back(high);
        }
        return ans;
    }
};