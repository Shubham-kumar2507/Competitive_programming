class Solution {
public:
    int scoreOfString(string s) {
        int h=1;
        int t=0;
        int ans=0;
        while(h<s.length()){
            ans += abs(s[t]-s[h]);
            h++;
            t++;
        }
        return ans;
    }
};