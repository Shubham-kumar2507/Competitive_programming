class Solution {
public:
void dfs(int u, vector<bool>& vis, unordered_map<int,vector<int>>& adj){
    vis[u]= true;
    for(int &v:adj[u]){
        if(!vis[v]){
            dfs(v,vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isC) {
        int n=isC.size() , cnt=0;
        unordered_map<int,vector<int>> adj;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isC[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
            cnt++;
            dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};