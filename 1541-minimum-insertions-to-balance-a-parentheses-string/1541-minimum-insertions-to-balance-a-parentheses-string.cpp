class Solution {
public:
    int minInsertions(string s) {
        // string p = "(()))(()))()())))";
        // CONSECUTIVE hone chhaiye
        // AHH
        // pehle fix karo, odd number of ) nahi aa sakte bc.
        // odd ho to even karo jaldi se.


        int ans = 0;
        string s2;
        int close = 0;

        for(char c:s){
            if(c == '('){
                if(close&1){
                    ans ++;
                    s2 += ')';
                }
                close = 0;
            }else close ++;
            s2 += c;
        }

        int opens = 0;
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == '(') opens += 2;
            else{
                if(opens == 0){
                    ans += 1;
                    opens += 1;
                }else opens --;
            }
        }
        return ans + opens;
    }
};