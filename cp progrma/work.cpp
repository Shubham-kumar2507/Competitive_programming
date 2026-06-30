//find the number of a binary string with no consecutive ones that can be formed using binary string of length N.
#include <bits/stdc++.h>
using namespace std;
int countStrings(int n) {
    if (n == 0) return 1; 
    if (n == 1) return 2; 
    
    vector<int> dp(n + 1);
    dp[0] = 1; 
    dp[1] = 2; 
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}
int main(){
    int n;
    cout << "Enter the length of the binary string: ";
    cin >> n;
    cout << "Number of binary strings with no consecutive ones: " << countStrings(n) << endl;
    return 0;
}