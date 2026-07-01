#include <bits/stdc++.h>

using namespace std;
long long rb = 0, rs= 0, rc = 0;

long long nb, ns, nc;
long long pb, ps, pc;
long long r;
bool isValid(long long x) {
    long long neb = max(0LL, x * rb - nb);
    long long nes = max(0LL, x * rs - ns);
    long long nec = max(0LL, x * rc - nc);
    
    long long tc = neb*pb +nes*ps + nec*pc;
    
    return tc <= r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string re;
    cin >> re;
    
    for (char ch : re) {
        if (ch == 'B') rb++;
        else if (ch == 'S') rs++;
        else if (ch == 'C') rc++;
    }
    
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    
    long long low = 0, high = 1e13; 
    long long ans = 0;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (isValid(mid)) {
            ans = mid;    
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans <<endl;
    
    return 0;
}