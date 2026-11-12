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
    void dfs(TreeNode* root, int ts,int& res){
        if(root==NULL) return;
        ts =ts*10+(root->val);
        if(!root->left && !root->right) {
            res+=ts;
            return;
        }
        dfs(root->left,ts,res);
        dfs(root->right,ts,res);
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        dfs(root,0,res);
        return res;
    }
};