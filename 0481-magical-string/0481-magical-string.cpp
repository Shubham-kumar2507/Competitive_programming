class Solution {
public:
    int magicalString(int n) {
        if(n<=0) return 0;
       if(n<=3) return 1;
        string s= "122";
        int h=2;
        int num= 1;
        int cnt =1;
        while(n>s.length()){
            int r= s[h]-'0';
            for(int i=0;i<r && s.length()<n; i++){
                s.push_back(num+'0');
                if(num==1){
                    cnt++;
                }
            }
            num = 3 - num;
            h++;
        }
        return cnt;

    }
};