class Solution {
public:
    unordered_map<int, vector<int>> graph;
    void dfs(int node, unordered_set<int>& curr_visited){
        curr_visited.insert(node);

        for(int i:graph[node]){
            if(curr_visited.find(i)==curr_visited.end()){
                dfs(i, curr_visited);
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

        vector<int> global_visited(n, 0);
        int ans = 0, size, flag;

        for(int i=0; i<n; i++){
            if(!global_visited[i]){
                unordered_set<int> curr_visited; // marks jo abhi dfs me visit kare nodes.
                dfs(i, curr_visited);
                size = curr_visited.size()-1; 
                flag = 1;

                for(int j:curr_visited){
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