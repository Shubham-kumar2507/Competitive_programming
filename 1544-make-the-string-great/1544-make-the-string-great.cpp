class Solution {
public:
    string makeGood(string s) {
       
        string res="";
       for(char &ch: s){
        if(!res.empty()&& abs(res.back()-ch)==32){
            res.pop_back();
        }else res.push_back(ch);
       }
        return res;
    }
};