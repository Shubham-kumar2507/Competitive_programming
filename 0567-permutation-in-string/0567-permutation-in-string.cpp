class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),n2=s2.size();
        if(n>n2) return false;
        
        unordered_map<char, int> s1_m,s2_m;
      
        for(int i=0;i<n;i++){
            s1_m[s1[i]]++;
            s2_m[s2[i]]++;
        }
        if(s1_m==s2_m) return true;

        for(int i=n;i<n2;i++){

            s2_m[s2[i-n]]--;

            if(s2_m[s2[i-n]]==0) s2_m.erase(s2[i-n]);

            s2_m[s2[i]]++;

            if(s2_m==s1_m) return true;
        }
        return false;
    }
};