class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // FUCK BHAI. kar leta ye to mai yar.
        // pura xor lele pehle. check xor me 1 konse hai
        // ex XOR = 5. 0th and 2rd bit 1 hai. koi bhi ek bit lelo. ex 0th bit lelo
        // ye bit hamare 2 answers me DIFFER karega. that means ek answer me ye bit 1 hoga ek me 0.
        // take all the elements with 0th bit 1 on one side, 0th bit 0 on second side.
        // xor em all. mil gaya answer. DAMN


        int xor_all = 0;
        for(int i:nums) xor_all ^= i;

        int bit = 1;
        while(true){
            if(bit&xor_all) break;
            bit <<= 1;
        }
        
        int xor1 = 0, xor2 = 0;

        for(int i:nums){
            if(i&bit) xor1 ^= i;
            else xor2 ^= i;
        }
        return {xor1, xor2};
    }
};