class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int tts= 0;
        for(int i=0;i<n;i++){
            unordered_set<int> dist;
            for(int j=i;j<n;j++){
                dist.insert(nums[j]);
                int cnt= dist.size();
                tts+=cnt*cnt;
            }
        }
        return tts;
    }
};