class Solution {
public:
int n;
void bfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& vis){
    queue<int> q;
    q.push(u);
    vis[u]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int &v: adj[curr]){
            if(!vis[v]){
              bfs(adj,v,vis);
                
            }
        }
    }

}
    int findCircleNum(vector<vector<int>>& isC) {
       n= isC.size();
       unordered_map<int,vector<int>> adj;

       for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(isC[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
       }
       int cnt=0;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(adj,i,vis);
            cnt++;
        }
    }
    return cnt;
    }
};