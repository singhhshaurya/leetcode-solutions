class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    vector<long long int> dist;
    int n; long long k;

    int dijkstra(int mid){
        dist.assign(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.push({0, 0});
        int node;
        long long curr_dist;

        while(heap.size()){
            auto i = heap.top();
            curr_dist = i.first, node = i.second;
            heap.pop();
            if(curr_dist > dist[node]) continue;
            for(auto& i:graph[node]){
                if(i.second >= mid && curr_dist + i.second < dist[i.first]){
                    dist[i.first] = curr_dist + i.second;
                    heap.push({dist[i.first], i.first});
                }
            }
        }

        return dist[n-1] <= k;
        
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k2) {
        // minimum edge must be MAXIMUM. whoa.
        // binary search on what final answer will be.
        // each edge >= mid hona chahiye. iss constraint k sath dijkstra laga do bc
        // if shortest path > k high = mid-1, else low = mid + 1 hell naw mick foley!
        
        n = online.size();
        k = k2;
        graph.assign(n, vector<pair<int, int>>());

        unordered_set<int> edges_lengths1 = {-1};

        for(auto& i:edges){
            if(online[i[0]] && online[i[1]]){
                graph[i[0]].push_back({i[1], i[2]});
                edges_lengths1.insert(i[2]);
            }
        }
        vector<int> edges_lengths(edges_lengths1.begin(), edges_lengths1.end());

        sort(edges_lengths.begin(), edges_lengths.end());
        // for(int i:edges_lengths) cout << i << " ";
        int low = 0, high = edges_lengths.size()-1, mid;

        while(low<=high){
            mid = (low+high)/2;
            // cout << mid << " ";
            if(dijkstra(edges_lengths[mid])) low = mid + 1;
            else high = mid - 1;
        }

        if(high == -1) return -1;
        return edges_lengths[high];
    }
};