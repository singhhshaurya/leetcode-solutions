class Solution {
public:
    int m, n;
    vector<vector<vector<int>>>memo;
    bool dp(int score, int x, int y, vector<vector<char>>& grid){
        // cout << x << " " << y << " " << score << "\n";
        if(x == m-1 && y == n-1 && score==1) return true;
        if(x == m || y == n) return false;
        if(score > (m+n)/2 || score < 0) return false;
        if(memo[x][y][score]) return false;

        int adder = grid[x][y] == '(' ? 1 : -1;
        if(dp(score+adder, x+1, y, grid)) return true;
        if(dp(score+adder, x, y+1, grid)) return true;

        memo[x][y][score] = 1;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        // aight aight aight aight aight aight aight aight 
        // '(' means +1, ')' means -1. 0 score karna hai last me thats it.
        // (m+n)/2 ke upar nahi jaa sakta score.
        // ezpz hai phir to.
        // (nsquare)*(m+n/2) ncube = 1000000 = 10**6 badiya
        m = grid.size(), n = grid[0].size();
        if(grid[0][0] != '(' || grid[m-1][n-1] != ')') return false;
        memo.assign(m, vector<vector<int>>(n, vector<int>((m+n)/2 + 1, 0)));
        return dp(0, 0, 0, grid);

    }
};