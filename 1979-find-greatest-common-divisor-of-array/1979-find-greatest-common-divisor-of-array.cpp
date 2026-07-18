class Solution {
public:
int findGCD(int a, int b) {
    return b == 0 ? a : findGCD(b, a % b);
}
    int findGCD(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int a=nums[0];
       int b=nums[nums.size()-1];
       return findGCD(a,b); 
    }
};