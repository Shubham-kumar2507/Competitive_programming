class Solution {
public:
    int smallestNumber(int n, int t) {
      while(1){
        int j=n,k=1;
        while(j>0){
            int l=j%10;
            k *=l;
            j/=10;
            if(k%t==0) return n;
        }
        n++;
      }  
    }
};