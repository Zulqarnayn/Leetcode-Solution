class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> color(size);
        
        queue<int> q;
        
        for(int idx = 0; idx < size; idx++) {
            if (color[idx]) continue;
            
            color[idx] = 1;
            q.push(idx);
            int v = idx;
            
            while(!q.empty()) {
                v = q.front();
                q.pop();

                for(auto u: graph[v]) {
                    if(!color[u]) {
                        color[u] = -color[v];
                        q.push(u);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};