/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// int solve1(TreeNode* root){
//     if(root==NULL) return 0;
//     queue<TreeNode*>q;
//     q.push(root);
//     int maxsum=INT_MIN;
//     int res=0;
//     int cl=1;
//     while(!q.empty()){
//         int n= q.size();
//         int cs=0;
//         while(n--){
//         auto node= q.front();
//         q.pop();
//         cs += node->val;
//         if(node->left!=NULL) q.push(node->left);
//         if(node->right!=NULL) q.push(node->right);

//         }
//         if(cs>maxsum){
//             maxsum = cs;
//             res = cl;
//         }
//         cl++;
//     }
//     return res;
// }
map<int,int> mp;
void solve2(TreeNode* root,int lvl){
    if(root==NULL) return;
    mp[lvl]+=root->val;
    solve2(root->left,lvl+1);
    solve2(root->right,lvl+1);
}
    int maxLevelSum(TreeNode* root) {
        //return solve1(root);
        mp.clear();
        solve2(root,1);
        int ms=INT_MIN;
        int res=0;
        for(auto &it : mp){
            int lvl = it.first;
            int sum = it.second;
            if(sum>ms){
                ms=sum;
                res=lvl;
            }
        }
            return res;
    }
};