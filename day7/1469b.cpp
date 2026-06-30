#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n;
    int maxr = 0, sumr = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sumr += x;
        maxr = max(maxr, sumr);
    }
    cin >> m;
    int maxb = 0, sumb = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;
        sumb += x;
        maxb = max(maxb, sumb);
    }
    cout << maxr + maxb << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}