class Solution {
public:
    unordered_map<int, vector<int>> graph;

    void dfs(int node, vector<int>& visited){
        visited[node] = 1;
        for(int i:graph[node]){
            if(!visited[i]){
                dfs(i, visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // hell nah n = 50 only
        // dfs se pehle saare components dhundho. then check if they all are connected
        
        for(auto& i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector<int> global_visited(n, 0), curr_visited;
        int ans = 0, size, flag;

        for(int i=0; i<n; i++){
            if(!global_visited[i]){
                curr_visited =  vector<int>(n, 0); // marks jo abhi dfs me visit kare nodes.
                dfs(i, curr_visited);
                size = count(curr_visited.begin(), curr_visited.end(), 1) - 1; 
                flag = 1;

                for(int j=0; j<n; j++){
                    if(!curr_visited[j]) continue;
                    global_visited[j] = 1;
                    if(graph[j].size()<size){
                        flag = 0;
                        break;
                    }
                }
                if(flag) ans += 1;
            }
        }
        return ans;
    }
};