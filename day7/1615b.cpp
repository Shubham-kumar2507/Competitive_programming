// #include<bits/stdc++.h>
// using namespace std;

// int pre[200005][20];

// void pc(){
//     for(int i=1;i<200005;i++){
//         for(int j=0;j<20;j++){
//             pre[i][j]=pre[i-1][j]+((i>>j)&1);
//         }
//     }
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;
//     int ans=0;
//     for(int i=0;i<20;i++){
//         int k=pre[r][i]-pre[l-1][i];
//         ans=max(ans,k);
//     }
//     cout<<(r-l+1)-ans<<"\n";
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     pc();
//     int t;
//     cin>>t;
//     while(t--) solve();
// }
#include <bits/stdc++.h>
using namespace std;

int csb(int x,int b){
    int p=1<<(b+1);
    int fb=(x+1)/p;
    int r=(x+1)%p;
    return fb*(1<<b)+max(0,r-(1<<b));
}
void solve(){
    int l,r;
    cin>>l>>r;
    int mx=0;
    for(int i=0;i<20;i++){
        mx=max(mx,csb(r,i)-csb(l-1,i));
    }
    cout<<(r-l+1)-mx<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}


