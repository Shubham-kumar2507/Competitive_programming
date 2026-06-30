#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<long long> a(n), pre(n+1,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<pre[n-x+y]-pre[n-x]<<endl;
    }

return 0;

}