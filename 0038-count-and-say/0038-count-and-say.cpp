class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string say = countAndSay(n-1);
        string res="";
        int i=0;
        while(i<say.length()){
            char ch=say[i];
            int cnt=1;
            while(i<say.length()-1 && say[i]==say[i+1]){
               cnt++;
                i++;
                
            }
            res+=to_string(cnt)+string(1,ch);
            i++;
        }
        return res;
    }
};