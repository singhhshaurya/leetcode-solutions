class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // reserved can be 10**4
        // if all available select 2,3,4,5 then 6,7,8,9 obv.
        // seems easy. total answer leke minus kar sakte waise.

        int ans = 2*n;
        sort(reservedSeats.begin(), reservedSeats.end());

        int ptr = 0;
        while(ptr < reservedSeats.size()){
            // cout << ptr << " ";
            int row = reservedSeats[ptr][0];
            vector<int> seats(10);
            while(ptr < reservedSeats.size() && reservedSeats[ptr][0]==row){
                seats[reservedSeats[ptr++][1]-1] = 1;
            }
    
            // check if all empty ho.
            int all = 1;
            for(int i=1; i<9; i++){
                if(seats[i]) all = 0;
            }          
            if(all) continue;
            // now 2 to nahi honge. check if 1 possible

            for(int i=0; i<3; i++){
                int all = 1;
                for(int j=1; j<5; j++){
                    if(seats[4*i + j - 2*i]) all = 0;
                }
                if(all){
                    ans += 1;
                    break;
                }
            }
            ans -= 2;  
        }
        return ans;
    }
};