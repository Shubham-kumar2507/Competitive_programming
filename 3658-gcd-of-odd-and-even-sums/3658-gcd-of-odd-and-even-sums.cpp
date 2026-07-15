class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int os=0;
        int es=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0){
                os+=i;
            }else{es+=i;}
        }
        return gcd(os,es);
    }
};