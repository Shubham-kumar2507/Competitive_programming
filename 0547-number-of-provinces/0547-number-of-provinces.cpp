class Solution {
public:
int n;
void bfs(vector<vector<int>>& isC, int u, vector<bool>& vis){
    queue<int> q;
    q.push(u);
    vis[u]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(!vis[v] && isC[u][v]==1){
              bfs(isC,v,vis);
                
            }
        }
    }

}
    int findCircleNum(vector<vector<int>>& isC) {
       n= isC.size();
    //    unordered_map<int,vector<int>> adj;

    //    for(int i=0;i<n;i++){
    //     for(int j=0; j<n; j++){
    //         if(isC[i][j]==1){
    //             adj[i].push_back(j);
    //             adj[j].push_back(i);
    //         }
    //     }
    //    }
       int cnt=0;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(isC,i,vis);
            cnt++;
        }
    }
    return cnt;
    }
};