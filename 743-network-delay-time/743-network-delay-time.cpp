typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 1e9;
        
        vector<vector<pii>> adjMatrix(n + 1);
        vector<bool> visited(n+1, false);
        vector<int> dist(n+1, inf);
        
        for(const auto &time: times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adjMatrix[u].push_back({v, w});
        }
        
        //https://www.geeksforgeeks.org/implement-min-heap-using-stl/
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.emplace(0, k);
        dist[k] = 0;
        
        while(!pq.empty()) {
            int u = pq.top().second; pq.pop();
            if(visited[u]) continue;
            visited[u] = true;
            
            for(auto& to: adjMatrix[u]) {
                int v = to.first, w = to.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        
        int ans = *max_element(dist.begin() + 1, dist.end()); // because we took extra element.
        return ans == inf? -1 : ans;
    }
};