#include <bits/stdc++.h>
using namespace std;

int n;
long long S;
vector<long long> a;

long long gms(int k) {
    if (k == 0) return 0;
    vector<long long> cc(n);
    for (int i = 0; i < n; ++i) {
        cc[i] = a[i] + (1LL * (i + 1) * k);
    }
    sort(cc.begin(), cc.end());
    long long ts = 0;
    for (int i = 0; i < k; ++i) {
        ts += cc[i];
    }
    if (ts <= S) {
        return ts;
    }
    return -1;
}
int main() {

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int low = 0, high = n;
    int mk = 0;
    long long mco = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long cost = gms(mid);

        if (cost != -1) {
            mk = mid;        
            mco = cost;    
            low = mid + 1;      
        } else {
            high = mid - 1;    
        }
    }

    cout << mk << " " << mco << endl;

    return 0;
}