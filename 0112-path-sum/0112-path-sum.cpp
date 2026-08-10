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
  bool fill(TreeNode* root, int sum, int& ts){
        if(root==NULL) return false;

        sum+=root->val;
        if(root->left==NULL && root->right==NULL) {
            if(sum==ts)
                return true;
            return false;
        }
        return fill(root->left,sum,ts) ||
        fill(root->right,sum,ts);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
             int sum =0;
        return fill(root, sum,targetSum);
    }
};