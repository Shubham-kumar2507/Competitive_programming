class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0;
        int cnt2=0;
        int n=s.length();
        for (char &c : s) {
        c = tolower(static_cast<unsigned char>(c));
    }
        for(int i=0;i<n/2;i++){
            if(s[i]=='a'||s[i]=='e' ||s[i]=='i' || s[i]=='o' || s[i]=='u') cnt++;
        }
        for(int i=n/2;i<n;i++){
            if(s[i]=='a'||s[i]=='e' ||s[i]=='i' || s[i]=='o' || s[i]=='u') cnt2++;
        }
        return cnt==cnt2;
    }
};