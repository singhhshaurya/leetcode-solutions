class Solution {
public:
    int checker(vector<vector<int>>& img1, vector<vector<int>>& img2){
        int ans = 0;
        for(int i=0; i<img1.size(); i++){
            for(int j=0; j<img1.size(); j++){
                ans += img1[i][j]&img2[i][j];
            }
        }
        return ans;
    }
    void convert(pair<int, int> change, vector<vector<int>>& img, vector<vector<int>>& img_converted){
        int n = img.size();
        int x=change.first, y=change.second;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i-x < 0 || j-y < 0 || i-x >= n || j-y >= n){
                    img_converted[i][j] = 0;
                }else{
                    img_converted[i][j] = img[i-x][j-y];
                }
            }
        }


    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // 30 hai. hmm
        // sequence of moves kya ho sakte hai.
        // ya to left ya to right, dono to nahi honge. same with up and down
        // once all left/right. then all up/down aise segragate kr sakte hai
        // so it gets nsquare. and converting then checking makes it ncube.
        // okay okay okay

        vector<vector<int>> img_copy = img1;

        int n = img1.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                convert({i, j}, img_copy, img1);

                ans = max(ans, checker(img1, img2));
                convert({-i, j}, img_copy, img1);
                ans = max(ans, checker(img1, img2));
                convert({i, -j}, img_copy, img1);
                ans = max(ans, checker(img1, img2));
                convert({-i, -j}, img_copy, img1);
                ans = max(ans, checker(img1, img2));
            }
        }
        return ans;


    }
};