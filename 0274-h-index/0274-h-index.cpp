class Solution {
public:
    int hIndex(vector<int>& ci) {
        sort(ci.begin(),ci.end());
        int n=ci.size();
        int l=0,r=n-1;
        while(l<=r){
           int mid=l+(r-l)/2;
           int pap=n-mid;
           if(ci[mid]==pap){
            return pap;
           }else if(ci[mid]<pap){
            l=mid+1;
           }else{
            r=mid-1;
           }

        }
        return n- l;
    }
};