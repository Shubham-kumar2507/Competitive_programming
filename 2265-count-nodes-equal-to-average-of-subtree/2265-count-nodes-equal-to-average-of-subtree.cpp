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
    pair<int,int> solve(TreeNode* root, int &res){
        if(!root) return {0,0};

        pair<int,int> l=solve(root->left, res);
        pair<int,int> r=solve(root->right,res);
        int ts = l.first+r.first+root->val;
        int tc= l.second+r.second+1;

        int avg = ts/tc;

        if(avg==root->val){
            res++;
        }
        return{ts,tc};
    }
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        auto ans=solve(root,res);
        return res;
    }
};