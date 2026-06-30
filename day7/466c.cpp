#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3!=0){
        cout<<0<<endl;
        return 0;
    }
    long long t1=sum/3;
    long long t2=t1*2;
    long long cs=0,cnt=0,ans=0;
    for(int i=0;i<n-1;i++){
        cs+=a[i];
        if(cs==t2) ans+=cnt;
        if(cs==t1) cnt++;
    }
    cout<<ans<<endl;
}