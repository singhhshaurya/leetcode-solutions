class Solution {
public:
    int minJumps(vector<int>& arr) {
        // okay okay okay
        // either i-1, i+1 or same number pe chale jao kahi bhi 
        // if we reach anywhere with nums[-1] to 1 jump me nums[-1] pahuch sakte.
        // dijkstra laga sakte hai? bahut saare edges ho sakte phir if lots of similar ho
        // undirected bhi banana padega na bc
        // bfs laga de na bas? should work?
        // ek node sabse pehle visit hogaya bas baad me nahi hoga visit.

        int n = arr.size();

        unordered_map<int, vector<int>> table;
        for(int i=0; i<arr.size(); i++){
            table[arr[i]].push_back(i);
        }


        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> visited(n, 0);
        int ind, dist;
        while(q.size()){
            auto& node = q.front();
            ind = node.first;
            dist = node.second;
            q.pop();

            visited[ind] = 1;
            if(ind == arr.size()-1) return dist;

            if(ind > 0 && !visited[ind-1]) q.push({ind-1, dist+1});
            if(ind < n-1 && !visited[ind+1]) q.push({ind+1, dist+1});

            for(int i:table[arr[ind]]){
                if(!visited[i]) q.push({i, dist+1});
            }
            table[arr[ind]].clear();
        }
        return -1;

    }
};