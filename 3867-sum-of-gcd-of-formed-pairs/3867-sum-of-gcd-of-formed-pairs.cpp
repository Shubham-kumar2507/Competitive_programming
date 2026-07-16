class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans=0;
        int m=0;
        int n=nums.size();
        for(int& i:nums){
            m=max(m,i);
            i=gcd(i,m);
        }
        sort(nums.begin(),nums.end());
        for(int i=0, j=n-1; i<j;++i,--j){
            ans+=gcd(nums[i],nums[j]);
        }
        return ans;
    }
};