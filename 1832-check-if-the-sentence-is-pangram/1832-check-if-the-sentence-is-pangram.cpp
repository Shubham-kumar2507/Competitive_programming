class Solution {
public:
    bool checkIfPangram(string s) {
        // set<char> ch(s.begin(), s.end());
        // int n=ch.size();
        // if(n<26) return false;
        // return true;
        vector<int> arr(26,0);

        for(char &c:s){
            int n=c-'a';
            arr[n]++;
        }
        for( int &cnt: arr){
            if(cnt==0)return false;
        }
        return true;
    }
};