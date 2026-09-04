class Solution {
public:

vector<int> topos(unordered_map<int, vector<int>>& adj ,int n, vector<int>& ind){
        queue<int> q;
        vector<int> res;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(ind[i]==0){ 
                q.push(i);
                res.push_back(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v: adj[u]){
                ind[v]--;
                if(ind[v]==0){
                cnt++;
                q.push(v);
                res.push_back(v);
                }
            }
        }
        if(cnt==n) return res;

        return {};
    }



    vector<int> findOrder(int numC, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        vector<int> ind(numC,0);

        for(auto &vec:pre){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            ind[u]++;
            
        }
        return topos(adj,numC, ind);
    }
};