class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN , mi=INT_MAX;
        int a=0, b=0;
        for(int i=0;i<n;i++){

            if(nums[i]>mx){
                mx=nums[i];
                a=i;
            } 
            if(nums[i]<mi){
                mi=nums[i];
                b=i;
            }
        }
        int i = min(a, b);
        int j = max(a, b);
        int both_front = j + 1;
        int both_back = n - i;
        int front_and_back = (i + 1) + (n - j);
        return min({both_front, both_back, front_and_back});

    }
};