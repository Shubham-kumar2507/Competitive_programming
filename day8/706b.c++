#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> pr(n);
    for (int i = 0; i < n; i++) {
        cin >> pr[i];
    }
    sort(pr.begin(), pr.end());

    int q;
    cin >> q;
    while (q--) {
        int co;
        cin >> co;
        auto ans = upper_bound(pr.begin(), pr.end(), co) - pr.begin();
        cout << ans << "\n";
    }
    return 0;
}