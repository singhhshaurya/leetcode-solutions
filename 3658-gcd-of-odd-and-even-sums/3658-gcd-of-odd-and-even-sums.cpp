class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // n(n+1) gives even sum
        // odd ke liye 2*n nos me se even hata do
        // 2n*(2n+1)/2 - n(n+1)
        // n*(2n+1) - n(n+1)
        // n*(2n+1-n-1) = n*(2n-n)
        // = nsquare
        // gcd = n

        return n;
    }
};