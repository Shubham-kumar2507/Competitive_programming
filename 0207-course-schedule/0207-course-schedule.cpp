class Solution {
public:
    bool topos(unordered_map<int, vector<int>>& adj ,int n, vector<int>& ind){
        queue<int> q;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(ind[i]==0){ 
                q.push(i);
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
                }
            }
        }
        if(cnt==n) return true;

        return false;
    }

    bool canFinish(int numC, vector<vector<int>>& pre) {
       unordered_map<int, vector<int>> adj;
       vector<int> ind(numC,0);//kahn's algo

        for(auto &vec: pre){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            ind[a]++;
        }
        //if cycle is present, not possible

        return topos(adj,numC,ind);
    }
};