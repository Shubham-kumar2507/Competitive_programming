class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = 0; 
        int n = s.length(); 
        for(int i = 0; i<n; i++) if(s[i] =='1') cnt1++; 
        int prevZeros = -1, ans = 0; 
        int i = 0; 
        while(i<n){
            int j = i; 
            while(j < n && s[j] == s[i]) j++; 
            int len = j - i; 
            if(s[i]=='0'){ 
                if(prevZeros != -1) ans = max(ans, prevZeros+len); 
                prevZeros = len; 
            }
            i = j; 
        }
        return cnt1 + ans; 
    }
};