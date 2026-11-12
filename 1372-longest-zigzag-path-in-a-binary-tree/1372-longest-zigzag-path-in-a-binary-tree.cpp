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
int maxpath=0;
void solve(TreeNode* root, int l, int r){
    if(root==NULL) return;
    maxpath=max(maxpath,max(l,r));
    solve(root->left,0,l+1);
    solve(root->right,r+1,0);
}
    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        return maxpath;
    }
};