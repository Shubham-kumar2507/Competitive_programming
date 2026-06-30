
#include <bits/stdc++.h>
using namespace std;    

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int p=1;
        
        for(int i = 0; i < 2*n; i++){
            for(int j = 0; j < n; j++){
               if(p>0) cout<<"##";
               else cout<<"..";
               p*=-1;
            }
            if(i%2==0) p*=-1;
            if(n%2==0) p*=-1;
            cout<<"\n";
        }
    }
    
    return 0;
}
