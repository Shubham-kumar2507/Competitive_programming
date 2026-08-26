class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        // if((n==0||n==1) || (n==2&&(nums[0]<=nums[1]))) return res ;
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[i]>nums[j]) cnt++;
        //     }
        //     res[i]=cnt;
        // }
        vector<int> sorted;
        for (int i = n-1; i >= 0; --i) {
            auto ins = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            int count = ins-sorted.begin();
            res.push_back(count);
            sorted.insert(ins, nums[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};