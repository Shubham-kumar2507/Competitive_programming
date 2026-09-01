class Solution {
public:
int n;
void dfs(int u, vector<bool>& vis, vector<vector<int>>& isC){
    vis[u]= true;
    for(int v=0;v<n;v++){
        if(!vis[v] && isC[u][v]==1){
            dfs(v,vis,isC);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isC) {
         n=isC.size() ;
         int cnt=0;
        //unordered_map<int,vector<int>> adj;
        vector<bool> vis(n,false);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isC[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }

        for(int i=0;i<n;i++){
            if(!vis[i]){
            cnt++;
            dfs(i,vis,isC);
            }
        }
        return cnt;
    }
};