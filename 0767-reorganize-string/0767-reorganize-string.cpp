class Solution {
public:
    string reorganizeString(string s) {
        int n= s.length();
        vector<int> cnt(26,0);
        int mf=0;
        char mc='a';
        for(char c:s){
            cnt[c-'a']++;
            if(cnt[c-'a']>mf){
                mf = cnt[c-'a'];
                mc=c;
            }
        }
        if(mf>(n+1)/2){
            return "";
        }
        string res(n,' ');
        int idx=0;
        while(cnt[mc-'a']>0){
            res[idx]=mc;
            idx+=2;
            cnt[mc -'a']--;
        }
        for(int i=0;i<26;i++){
            while(cnt[i]>0){
                if(idx>=n){
                    idx=1;
                }
                res[idx]=(char)(i+'a');
                idx +=2;
                cnt[i]--;
            }
        }
        return res;
    }
};