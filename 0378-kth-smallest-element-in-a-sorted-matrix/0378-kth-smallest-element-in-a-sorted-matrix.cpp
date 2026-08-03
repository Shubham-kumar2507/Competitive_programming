class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        for(auto& row:matrix){
            res.insert(res.end(), row.begin(), row.end());
        }
        sort(res.begin(),res.end());
        int n=res.size();
        return res[k-1];
    }
};