// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end() ,[](int a, int b) {
//         return abs(a) < abs(b);
//         });
//         long long sum=0;
//         int n=nums.size();
//         for(int i=0; i<n; i++){
//             if(i<n/2){
//                 sum-=nums[i]*nums[i];
//             }else{
//                 sum+=abs(nums[i]*nums[i]);
//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        
        // Rearrange elements so that the smallest n/2 elements (by absolute value)
        // are placed before index 'mid'.
        auto comp = [](int a, int b) { return abs(a) < abs(b); };
        nth_element(nums.begin(), nums.begin() + mid, nums.end(), comp);
        
        long long max_sum = 0;
        
        // First half (smaller absolute values) gets subtracted
        for (int i = 0; i < mid; ++i) {
            max_sum -= 1LL * nums[i] * nums[i];
        }
        
        // Second half (larger absolute values) gets added
        for (int i = mid; i < n; ++i) {
            max_sum += 1LL * nums[i] * nums[i];
        }
        
        return max_sum;
    }
};