class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // string n final als
        // n.size() = num
        // sabka sum is sum
        // so mostly 9s bharne hai hame bas. phir last me 0-8 tak jo bhi ho then all zeroes.
        // bcoz squuare me yahi hota hai. increases MUCH faster than it decreases. Graph yaad karna.
        string ans(sum/9, '9');
        if(sum%9) ans.push_back('0'+sum%9);
        // cout << ans;

        if(ans.size() > num) return "";
        return ans + string(num-ans.size(), '0');



    }
};