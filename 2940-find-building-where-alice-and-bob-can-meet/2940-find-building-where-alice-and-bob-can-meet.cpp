class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        vector<int> ans(q, -1);
        vector<vector<pair<int, int>>> deferred(n);
        
        for (int i = 0; i < q; ++i){
            int u = queries[i][0];
            int v = queries[i][1];
            if (u > v) {
                swap(u, v);
            }if (u == v ||heights[u]<heights[v]){
                ans[i] = v;
            } else{
                deferred[v].push_back({heights[u], i});
            }
        }  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < n;++i) {
            while (!pq.empty() && pq.top().first < heights[i]){
                ans[pq.top().second] = i;
                pq.pop();
            }
            for (auto& query:deferred[i]){
                pq.push(query);
            }
        }
        
        return ans;
    }
};