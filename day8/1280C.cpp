#include <bits/stdc++.h>
using namespace std;

long long G, B;
int tn;

struct Edge{
    int to;
    long long wei;
};

vector<vector<Edge>> adj;
int dfs(int u, int p){
    int ssize = 1;

    for (auto& edge : adj[u]){
        int v = edge.to;
        long long w = edge.wei;

        if (v != p) {
            int chisi = dfs(v, u);
            if (chisi % 2 == 1){
                G += w;
            }
            B += min(chisi, tn - chisi) * w;

            ssize += chisi;
        }
    }
    return ssize;
}

void solve(){
    int k;
    cin >> k;
    tn = 2 * k;

    adj.assign(tn + 1, vector<Edge>());
    G = 0;
    B = 0;

    for (int i = 0; i < tn - 1; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0);

    cout << G << " " << B << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}