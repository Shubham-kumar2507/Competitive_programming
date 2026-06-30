//t-prime codeforces 230 B
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
bool is_prime[MAXN];

void sieve() {
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i * i < MAXN; i++) {
        if(is_prime[i]) {
            for(long long j = (long long)i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    sieve();
    
    int n;
    cin >> n;
    
    while(n--) {
        long long t;
        cin >> t;
        long long sq = sqrtl(t);
        if(sq * sq == t && sq < MAXN && is_prime[sq]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}