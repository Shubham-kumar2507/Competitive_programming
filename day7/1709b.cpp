#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> l(n, 0), r(n, 0);
    for (int i = 1; i < n; i++) l[i] = l[i - 1] + max(0LL, a[i - 1] - a[i]);
    for (int i = n - 2; i >= 0; i--) r[i] = r[i + 1] + max(0LL, a[i + 1] - a[i]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (x <= y) cout << l[y] - l[x] << "\n";
        else cout << r[y] - r[x] << "\n";
    }
}