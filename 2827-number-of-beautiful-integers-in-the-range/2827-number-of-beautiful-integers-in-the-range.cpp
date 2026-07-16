class Solution {
private:
    int k = 0;
    int dp[10][2][2][19][20];
    int solve(string& num, int idx, bool tight, bool started, int balance, int rem){
        if (idx == num.size()){
            return started && balance == 0 && rem % k == 0;
        }
        
        if (dp[idx][tight][started][balance + 10][rem] != -1){
            return dp[idx][tight][started][balance + 10][rem];
        }
        int lb = 0, ub = tight ? num[idx] - '0' : 9, ans=0;

        for (int dig = lb; dig <= ub; dig++){
            if (!started && dig == 0){
                ans += solve(num, idx + 1, false, false, 0, 0);
            }
            else {                
                ans += solve(num, idx + 1, tight && dig == ub, started || dig, balance + ((dig & 1) ? 1 : -1), (rem * 10 + dig) % k);
            }
        }
        return dp[idx][tight][started][balance + 10][rem] = ans;
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k = k;

        memset(dp, -1, sizeof(dp));
        string num2 = to_string(high);
        int right = solve(num2, 0, true, false, 0, 0);
        
        memset(dp, -1, sizeof(dp));
        string num1 = to_string(low - 1);
        int left = solve(num1, 0, true, false, 0, 0);

        return right - left;
    }
};