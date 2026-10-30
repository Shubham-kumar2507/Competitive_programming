class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v,w});
        }
        const int INF = 1e9 + 7;

        vector<vector<int>> dist(n, vector<int>(k+1, INF));

        priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>>pq;

        dist[0][1]=0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto[d,u,consec]=pq.top();
            pq.pop();
            if(d>dist[u][consec]) continue;

            if(u==n-1) return d;
            for(const auto& neighbor : graph[u]){
                int v = neighbor.first;
                int weight = neighbor.second;
                int next_consec = (labels[v]==labels[u])?consec +1:1;

                if(next_consec <=k){
                    if(d+weight<dist[v][next_consec]) {
                        dist[v][next_consec] = d+weight;
                        pq.push({dist[v][next_consec], v , next_consec});
                    }
                }
            }
        }
        int mint=INF;
        for (int c=1; c<=k;++c){
            mint = min(mint,dist[n-1][c]);
        }
        return (mint == INF)? -1 : mint;
    }
};