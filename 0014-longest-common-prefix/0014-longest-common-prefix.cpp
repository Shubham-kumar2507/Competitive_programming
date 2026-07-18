class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int j=strs.size();
        string a=strs[0];
        string b=strs[j-1];
        int n=min(a.length(),b.length());
        string res="";
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) break;
            res +=a[i];
        }
        return res;
    }
};