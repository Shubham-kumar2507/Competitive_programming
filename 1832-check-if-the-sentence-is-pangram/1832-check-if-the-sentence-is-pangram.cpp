class Solution {
public:
    bool checkIfPangram(string s) {
        set<char> ch(s.begin(), s.end());
        int n=ch.size();
        if(n<26) return false;
        return true;
    }
};