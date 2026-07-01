#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long low = 1, high = 2e9, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid - mid / n >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}