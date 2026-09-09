class Solution {
public:
    long long countCommas(long long n) {
        if(n<999) return 0;
        long long cnt =0;
        long long t=1000;
        while(n>=t){
            cnt +=(n-t+1);
            t *=1000;
        }
        return cnt;
    }
};