//friends pairing problem
//recursion

#include <bits/stdc++.h>
using namespace std;

int countPairings(int n) {
    // if (n == 0) return 1;
    // if (n == 1) return 1;
    // if (n == 2) return 2;

    // vector<int> dp(n + 1);
    // dp[0] = 1;
    // dp[1] = 1;
    // dp[2] = 2;

    // for (int i = 3; i <= n; ++i) {
    //     dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    // }

    // return dp[n];
    if (n <= 2) return n;
    return countPairings(n - 1) + (n - 1) * countPairings(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << countPairings(n) << endl;
    return 0;
}